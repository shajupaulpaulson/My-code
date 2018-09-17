#!/usr/bin/python

import sys
s = 'hi'
print s[1]## i
print len(s)## 2
print s + ' there'## hi there

pi = 3.14
##text = 'The value of pi is ' + pi## NO, does not work
text = 'The value of pi is '+ str(pi)## yes
print text

raw = r'this\t\n and that'
print raw ## this\t\n and that

multi = """It was the BEST of times.
It was the WORST of times."""
print multi

print ("Lower case letter")
#lower 
print multi.lower()
print (" ")

print ("Upper case letter")
#upper 
print multi.upper()
print (" ")

print ("Strip Whitespace letter at the begining or the end")
#strip whitespace
print multi.strip()
print (" ")

print ("Alphaletter")
#alpha numberical
print multi.isalpha()
alphatext='S@mple'
print alphatext.isalpha()#false will not work
alphatext2='123asd'
print alphatext2.isalpha()#false will not work Have to check?
print (" ")

print ("space check")
#space
print multi.isspace() #false non emtpy
textempty=' '
print textempty.isspace() #if only entire string is emtpy
print (" ")

print ("Digit in string")
#isDigit
print multi.isdigit()
#check
one='1' #only as string will not work as numbers
print one.isdigit()
two=2
print str(two).isdigit() #This also works
print (" ")

print ("Starting with")
print multi.startswith('IT')
print (" ")

print ("Ending with")
print multi.endswith('times.')
print (" ")

print ("Find with")
print multi.find('BEST')
print (" ")

print ("Replace with")
print multi.replace('BEST','KING')
print (" ")

print ("Split with")
print multi.split(' ')
print (" ")

print ("Join with")
print multi.join('----')
print '---'.join(multi)
print (" ")

print ("Print String slices")
print multi[1:4]
print multi[:]
print multi[4:100]
print multi[11:12]
print multi[10:]
print multi[:-1]
print multi[-10:-1]
print (" ")


text = "%d little pigs come out or I'll %s and %s and %s" % (3, 'huff', 'puff', 'blow down')
print text
 
text = ("%d little pigs come out or I'll %s and %s and %s" %
(4, 'guff', 'duff', 'blow down'))
print text

ustring = u'A unicode \u018e string \xf1'
s = ustring.encode('utf-8')
t = unicode(s, 'utf-8') 
print t==ustring

k='test'
l=3
if l>2:
    print 'inside if statement'
    if k == 'test' or k=='test1':
        print 'Inside Test'
    elif k == 'test2' or k=='test3':
        print 'Inside Test2'
    else:
        print 'In the else'

