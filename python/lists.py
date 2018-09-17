#!/usr/bin/python

import sys

colors = ['red', 'blue', 'green']
print colors[0]## red
print colors[2]## green
print len(colors)## 3

b = colors ## Does not copy the list

squares = [1, 4, 9, 16]
sum = 0
for num in squares:
    sum += num
print sum## 30

sum2=''
for num in colors:
    sum2 += num
print sum2## redbluegreen

list = ['red', 'blue', 'green']
if 'blue' in list:
    print 'yay'

## print the numbers from 0 through 99
for i in range(12):
    print i

a = ['red', 'blue', 'green', 'black', 'brown', 'orange','purple', 'yellow']
i = 0
while i < len(a):
    print a[i]
    i = i + 2

list = ['larry', 'curly', 'moe']
list.append('shemp')         ## append elem at end
list.insert(0, 'xxx')        ## insert elem at index 0
list.extend(['yyy', 'zzz'])  ## add list of elems at end
print list  ## ['xxx', 'larry', 'curly', 'moe', 'shemp', 'yyy', 'zzz']
print list.index('curly')    ## 2

list.remove('curly')         ## search and remove that element
list.pop(1)                  ## removes and returns 'larry'
print list  ## ['xxx', 'moe', 'shemp', 'yyy', 'zzz']

list1 = [1, 2, 3]
print list1.append(4)   ## NO, does not work, append() returns None
## Correct pattern:
print list1
list1.append(4)
print list1  ## [1, 2, 3, 4, 4]

list2 = []          ## Start as the empty list
list2.append('a')   ## Use append() to add elements
list2.append('b')

list3 = ['a', 'b', 'c', 'd']
print list3[1:-1]   ## ['b', 'c']
list3[0:2] = 'z'    ## replace ['a', 'b'] with ['z']
print list3         ## ['z', 'c', 'd']

list = ['larry', 'curly', 'moe']
print list.index('curly')
#print list.index(5)fails if index is not there

print list.sort()
print list
print list.reverse()
print list
print list1.pop(2)
print list3.remove('c')
