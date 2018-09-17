#!/usr/bin/python3.5

# import modules used here -- sys is a very standard one
import sys
import urllib.request

## Given a url, try to retrieve it. If it's text/html,
## print its base url and its text.
def wget(url):
  ufile = urllib.request.urlopen(url)  ## get file-like object for url
  info = ufile.info()   ## meta-info about the url content
  if info.gettype() == 'text/html':
    print ('base url:' + ufile.geturl())
    text = ufile.read()  ## read all its text
    print (text)

## Version that uses try/except to print an error message if the
## urlopen() fails.
def wget2(url):
  try:
    ufile = urllib.request.urlopen(url)
    if ufile.info().gettype() == 'text/html':
      print (ufile.read())
  except IOError:
    print ('problem reading url:', url)
	
		
wget('http://www.google.com/')
wget2('gmail.com')
