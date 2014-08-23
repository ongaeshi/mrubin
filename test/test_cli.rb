require 'minitest_helper'
require 'mrubin/cli'

module Mrubin
  class TestCli < MiniTest::Test
    def setup
      @orig_stdout = $stdout
      $stdout = @stringio = StringIO.new
    end

    def teardown
      $stdout = @orig_stdout
    end

    def test_default
      assert_match /mrubin \d+/, command("")
    end

    def test_exec
      command("exec #{testdir("./data")}")
    end

    private

    def testdir(path)
      File.expand_path(File.join(File.dirname(__FILE__), path))
    end

    def command(arg)
      CLI.start(arg.split)
      $stdout.string
    end
  end
end
