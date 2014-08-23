# Mrubin

Bind tool for mruby.

## Installation

    $ gem install mrubin

## Usage

Add a template file. You should have an extension of `.mrubin`, but is actually a Ruby script.

vector3.mrubin

```ruby
class Vector3
  attr_accessor :x
  attr_accessor :y
  attr_accessor :z
  
  def initialize(x, y, z)
  end

  def clone
  end

  def +(vec)
  end

  def *(scalar)
  end

  def ==(vec)
  end

  def[](index)
  end

  def inspect
  end
end
```

Put a `.mrubin` files wherever you like.

```
$ cd /path/to/dir
$ ls
vector3.mrubin
```

Execute.

```
$ mrubin
```

Created `BindVector3.cpp`.

```
$ ls
BindVector3.cpp
vector3.mrubin
```

BindVector3.cpp

```cpp
#include "mruby.h"
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

void vector3_init(mrb_state* mrb)
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
```
