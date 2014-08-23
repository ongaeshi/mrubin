module Mrubin
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
