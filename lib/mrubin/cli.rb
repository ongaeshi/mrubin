require 'mrubin/rclass'
require 'mrubin/version'

require 'find'
require 'thor'

module Mrubin
  class CLI < Thor
    class_option :help, :type => :boolean, :aliases => '-h', :desc => 'Help message'

    desc "generate", ""
    def generate(*args)
      dir = "."
      dir = args[0] if args.size > 0

      Find.find(dir) do |path|
        next if File.extname(path) != ".mrubin"

        rclass = RClass.new(path)

        write_file rclass.header_path, rclass.header_content
        write_file rclass.impl_path, rclass.impl_content
      end
    end

    desc "view", ""
    def view(*args)
      args.each do |path|
        rclass = RClass.new(path)
        puts "--- #{rclass.header_path} ---"
        puts rclass.header_content
        puts "--- #{rclass.impl_path} ---"
        puts rclass.impl_content
      end
    end

    no_tasks do
      # Override method for support -h 
      # defined in /lib/thor/invocation.rb
      def invoke_command(task, *args)
        if task.name == "help" && args == [[]]
          print "mrubin #{Mrubin::VERSION}\n\n"
        end
        
        if options[:help]
          CLI.task_help(shell, task.name)
        else
          super
        end
      end
    end

    private

    def write_file(path, content)
      if File.exists? path
        puts "Already exists: #{path}"
      else
        puts "Generate: #{path}"
        File.write(path, content)
      end
    end
    
  end
end
