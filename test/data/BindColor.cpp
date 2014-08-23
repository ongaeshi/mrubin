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

mrb_value r(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value r_set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value g(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value g_set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value b(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value b_set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value a(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value a_set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value clone(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value set_hex(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value to_hex(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value clamp(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value invert(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value normalize(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value lerp(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value hue(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value saturation(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value brightness(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value lightness(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value to_hsb(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value hue_set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value saturation_set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value brightness_set(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value set_hsb(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value equal(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value not_equal(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value add(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value sub(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value mul(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value div(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value aref(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value aref_set(mrb_state *mrb, mrb_value self)
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

void BindColor::Bind(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Color", mrb->object_class);

    mrb_define_class_method(mrb, cc, "test!"             , test_bang           , MRB_ARGS_REQ(1));
    mrb_define_class_method(mrb, cc, "hex"               , hex                 , MRB_ARGS_ARG(1, 1));
    mrb_define_class_method(mrb, cc, "hsb"               , hsb                 , MRB_ARGS_ARG(3, 1));

    mrb_define_method(mrb, cc,       "r"                 , r                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "r="                , r_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "g"                 , g                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "g="                , g_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "b"                 , b                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "b="                , b_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "a"                 , a                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "a="                , a_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "clone"             , clone               , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "set"               , set                 , MRB_ARGS_ARG(3, 1));
    mrb_define_method(mrb, cc,       "set_hex"           , set_hex             , MRB_ARGS_ARG(1, 1));
    mrb_define_method(mrb, cc,       "to_hex"            , to_hex              , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "clamp"             , clamp               , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "invert"            , invert              , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "normalize"         , normalize           , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "lerp"              , lerp                , MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,       "hue"               , hue                 , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "saturation"        , saturation          , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "brightness"        , brightness          , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "lightness"         , lightness           , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "to_hsb"            , to_hsb              , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "hue="              , hue_set             , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "saturation="       , saturation_set      , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "brightness="       , brightness_set      , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "set_hsb"           , set_hsb             , MRB_ARGS_ARG(3, 1));
    mrb_define_method(mrb, cc,       "=="                , equal               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "!="                , not_equal           , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "+"                 , add                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "-"                 , sub                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "*"                 , mul                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "/"                 , div                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "[]"                , aref                , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "[]="               , aref_set            , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "inspect"           , inspect             , MRB_ARGS_NONE());
}
