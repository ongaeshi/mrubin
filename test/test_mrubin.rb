require 'minitest_helper'

class TestMrubin < MiniTest::Unit::TestCase
  def test_that_it_has_a_version_number
    refute_nil ::Mrubin::VERSION
  end
end
