require 'mrubin/rclass'
require 'mrubin/version'

require 'active_support'
require 'active_support/core_ext'
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

        # Get klass from filename
        klass = File.basename(path, ".mrubin").classify.constantize

        # Generate a bind code
        rclass = RClass.new(klass)

        output_path = File.join File.dirname(path), "Bind#{klass.to_s}.cpp"
        File.write(output_path, rclass.to_s)
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
