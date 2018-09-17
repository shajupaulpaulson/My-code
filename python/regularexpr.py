#!/usr/bin/python

# import modules used here -- sys is a very standard one
import sys
import re

pat='I was in the well'
str='well'

match = re.search(str, pat)
print match
print re.search(str, pat)

# If-statement after search() tests if it succeeded
if match:
  print 'found', match.group() ## 'found word:well'
else:
  print 'did not find'

str='What is the word:cat and the word:bird'
match = re.search(r'word:\w\w\w\w', str)
print match.group()
multi = """It was the BEST of times.
It was the WORST of times."""

match = re.search(r'w.s', multi)
print match.group()	
str='My phone number is 1234567890'
match = re.search(r'\d\d\d', str) #integer and prints 123
str='My phone number is ##'
print match.group()
match = re.search(r'\W\W\W', str) #non letter or number also spcae
print match.group()
match = re.search(r'\s', multi)#whitespave 
print match.group()
match = re.search(r'\S\S', multi) #non whitespave
print match.group()
match = re.search(r'^It', multi) #Start of string
print match.group()
match = re.search(r'times.$', multi) #end of string put $ at the last
print match.group()
match = re.search(r'\w\w\w\w+', multi) #+ 1 or more occurrences of the pattern to its left, e.g. 'i+' = one or more i's 
print match.group()
str='My phone number is 1234567890'
match = re.search(r'\w*', multi) #* 0 or more occurrences of the pattern to its left 
print match.group()
match = re.search(r'\w?', str) #? match 0 or 1 occurrences of the pattern to its left 
print match.group()


str = 'embeede dr-D@google.com company'
match = re.search(r'\w+@\w+', str)
if match:
    print match.group()  ## 'D@google'
	
match = re.search(r'([\w.-]+)@([\w.-]+)', str)
if match:
    print match.group()   ## 'dr-D@google.com' (the whole match)
    print match.group(1)  ## 'dr-D' (the username, group 1)
    print match.group(2)  ## 'google.com' (the host, group 2)

print ' '
## Here re.findall() returns a list of all the found email strings
emails = re.findall(r'[\w\.-]+@[\w\.-]+', str) ## ['dr-D@google.com']
for email in emails:
    # do something with each found email string
    print email
	
# Open file
f = open('foo.txt', 'r')
# Feed the file text into findall(); it returns a list of all the found strings
strings = re.findall(r'o', f.read())
print strings
f.close()

str = 'embeede dr-D@google.com ompany, blah  gaby@google.com damn it'
tuples = re.findall(r'([\w\.-]+)@([\w\.-]+)', str)
print tuples  ## [('alice', 'google.com'), ('bob', 'abc.com')]
for tuple in tuples:
    print tuple[0]  ## username
    print tuple[1]  ## host

#special case for re
match = re.search(r'^It', multi,re.MULTILINE ) #For multiline
print match.group()
match = re.search(r's.', multi,re.DOTALL ) #matches new line of string 
print match.group()

print re.sub(r'([\w\.-]+)@([\w\.-]+)', r'\1@Xmen.com', str)
