#include "BindVector3.hpp"

#include "mruby/value.h"

namespace {
mrb_value x(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value x_set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value y(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value y_set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value z(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value z_set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value clone(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value add(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value mul(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value equal(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value aref(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value inspect(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

}

void BindVector3::Bind(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Vector3", mrb->object_class);



    mrb_define_method(mrb, cc,       "x"                 , x                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "x="                , x_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "y"                 , y                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "y="                , y_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "z"                 , z                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "z="                , z_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "clone"             , clone               , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "+"                 , add                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "*"                 , mul                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "=="                , equal               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "[]"                , aref                , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "inspect"           , inspect             , MRB_ARGS_NONE());
}
