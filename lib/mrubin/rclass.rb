# -*- coding: utf-8 -*-
require 'mrubin/rmethod'

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

    def bind_class_name
      "Bind#{@klass.to_s}"
    end

    def header_filename
      "#{bind_class_name}.hpp"
    end

    def header_path
      File.join File.dirname(@path), header_filename
    end

    def impl_path
      File.join File.dirname(@path), "#{bind_class_name}.cpp"
    end

    def header_content
      <<EOF
#pragma once

#include "mruby.h"

//----------------------------------------------------------
class #{bind_class_name} {
public:
    static void Bind(mrb_state* mrb);
};
EOF
    end

    def impl_content
      <<EOF
#include "#{header_filename}"

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
  end
end
