require 'mrubin/rclass'
require 'mrubin/version'

require 'find'
require 'thor'

module Mrubin
  class CLI < Thor
    class_option :help, :type => :boolean, :aliases => '-h', :desc => 'Help message'

    desc "exec", ""
    def exec(*args)
      dir = "."
      dir = args[0] if args.size > 0

      Find.find(dir) do |path|
        next if File.extname(path) != ".mrubin"

        # Load a Ruby script
        load path

        # Get a klass
        klass = ObjectSpace.each_object(Class).to_a.last

        # Generate a bind code
        rclass = RClass.new(klass)
        puts rclass.to_s
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
  end
end
