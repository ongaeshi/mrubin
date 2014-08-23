# -*- coding: utf-8 -*-
require 'active_support'
require 'active_support/core_ext'

module Mrubin
  class RClass
    def initialize(path)
      @path = path

      # Load a Ruby script
      load @path

      # Get klass from filename
      @klass = File.basename(@path, ".mrubin").classify.constantize

      # Collect singleton methods
      @singleton_methods = @klass.singleton_methods(false).map do |sym|
        RMethod.new(@klass.method(sym))
      end

      # Collect instance methods
      begin
        obj = @klass.new
      rescue ArgumentError => e
        raise e, "Can't define #{@klass}#initialize."
      end

      @instance_methods = @klass.instance_methods(false).map do |sym|
        RMethod.new(obj.method(sym))
      end
    end

    def implement_methods
      (@singleton_methods + @instance_methods).map {|method| method.implement }.join("\n")
    end

    def define_methods
      str = ""
      str += @singleton_methods.map {|method| method.define }.join("\n")
      str += "\n\n"
      str += @instance_methods.map {|method| method.define }.join("\n")
      str
    end

    def to_s
      <<EOF
#include "mruby.h"
#include "mruby/value.h"

namespace {
#{implement_methods}
}

void #{bind_class_name}::Bind(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "#{@klass.to_s}", mrb->object_class);

#{define_methods}
}
EOF
    end

    def bind_class_name
      "Bind#{@klass.to_s}"
    end

    def output_path
      File.join File.dirname(@path), "#{bind_class_name}.cpp"
    end
  end

  class RMethod
    DEFINE_SPAN = 20

    def initialize(method)
      @method = method
    end

    def implement
      <<EOF
mrb_value #{cfunc_name}(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}
EOF
    end

    def define
      rname = "\"#{ruby_name}\"".ljust(DEFINE_SPAN)
      cname = cfunc_name.ljust(DEFINE_SPAN)

      if @method.receiver.is_a?(Class)
        "    mrb_define_class_method(mrb, cc, #{rname}, #{cname}, #{cfunc_args});"
      else
        "    mrb_define_method(mrb, cc,       #{rname}, #{cname}, #{cfunc_args});"
      end
    end

    def cfunc_name
      str = @method.name.to_s

      str.sub("==",  "equal")
         .sub("!=",  "not_equal")
         .sub("+",   "add")
         .sub("-",   "sub")
         .sub("*",   "mul")
         .sub("/",   "div")
         .sub("[]",  "aref")
         .sub("[=",  "aset")
         .sub(/\!$/, "_bang")
         .sub(/\=$/, "_set")
    end

    def self.count_param(params)
      req = opt = 0
      
      params.each do |param|
        case param[0]
        when :req
          req += 1
        when :opt
          opt += 1
        else
          raise
        end
      end

      return req, opt
    end

    def cfunc_args
      param = @method.parameters

      if param.empty?
        "MRB_ARGS_NONE()"
      else
        req, opt = RMethod.count_param(param)

        if req == 0
          "MRB_ARGS_OPT(#{opt})"
        elsif opt == 0
          "MRB_ARGS_REQ(#{req})"
        else
          "MRB_ARGS_ARG(#{req}, #{opt})"
        end
      end
    end

    def ruby_name
      @method.name.to_s
    end
  end
end
