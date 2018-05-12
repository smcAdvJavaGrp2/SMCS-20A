Recall that you will need to give these executables permission to run 
using the chmod u+x or chmod +x command.

OSX is a bit finicky with file paths. So, as is, these executables will 
not look for the maze files in this directory. To run these executables 
you will have to move the maze files into your users/<USER> directory, 
the same directory that has your Downloads and Desktop folders. 

This is just for running these example executables.  Xcode manages all
your file paths. So when you're developing on your own, you'll need to 
either figure out where Xcode looks for these files by defualt or change
it to whatever you want by manipulating the project preferences. 