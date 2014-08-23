#include "mruby.h"
#include "mruby/value.h"

namespace {
mrb_value test_bang(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value hex(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value hsb(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

}

void color_init(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Color", mrb->object_class);

    mrb_define_class_method(mrb, cc, "test!"             , test_bang           , MRB_ARGS_REQ(1));
    mrb_define_class_method(mrb, cc, "hex"               , hex                 , MRB_ARGS_ARG(1, 1));
    mrb_define_class_method(mrb, cc, "hsb"               , hsb                 , MRB_ARGS_ARG(3, 1));


}
