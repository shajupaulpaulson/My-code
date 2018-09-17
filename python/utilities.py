#!/usr/bin/python

# import modules used here -- sys is a very standard one
import sys
import os
import commands
program_name = sys.argv[0]
arguments = sys.argv[1:]
count = len(arguments)


if len (sys.argv) != 2 :
    print "Usage: python ex.py "
    sys.exit (1)
	
## Example pulls filenames from a dir, prints their relative and absolute paths
def printdir(dir):
  filenames = os.listdir(dir)
  for filename in filenames:
    print filename  ## foo.txt
    print os.path.join(dir, filename) ## dir/foo.txt (relative to current dir)
    print os.path.abspath(os.path.join(dir, filename)) ## /home/nick/dir/foo.txt
    print os.path.dirname(os.path.abspath(os.path.join(dir, filename))) # prints directory name
    print os.path.basename(filename)#print file name
    print os.path.exists(filename)
    #os.mkdir(test1)
    #shutil.copy(test1, test2)
for x in sys.argv[1:]:
    print "Argument: ", x
    printdir(x)

def listdir(dir):
  cmd = 'ls -l ' + dir
  print "Command to run:", cmd   ## good to debug cmd before actually running it
  (status, output) = commands.getstatusoutput(cmd)
  if status:    ## Error case, print the command's output to stderr and exit
    sys.stderr.write(output)
    sys.exit(status)
  print output  ## Otherwise do something with the command's output
  cmd = 'cat foo.txt'
  os.system(cmd)
    
listdir(".")


try:
  ## Either of these two lines could throw an IOError, say
  ## if the file does not exist or the read() encounters a low level error.
  filename='test1.txt'
  f = open(filename, 'rU')
  text = f.read()
  f.close()
except IOError:
  ## Control jumps directly to here if any of the above lines throws IOError.
  sys.stderr.write('problem reading:' + filename)
  ## In any case, the code then continues with the line after the try/except
  
