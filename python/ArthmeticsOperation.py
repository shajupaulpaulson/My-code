#!/usr/bin/python

import sys

# Gather our code in a main() function
def add(i,j):
    result = i+j
    return result
    # add

def dif(i,j):
    result = i-j
    return result
    # dif

def mul(i,j):
    result = i*j
    return result
    # mul
	
def div(i,j):
    result = i/j
    return result
    #div	

def main():
    print add(10,5)
    print dif(10,5)
    print dif(5,15)
    print mul(10,5)
    print mul(10,-5)
    print div(10,5)
    print div(10,-5)
    print div(5,-15)
    print add('D','og')
    #print dif('D','og')
    #print mul('D','og')
    #print div('D','og')
    i1=input("What the first number? ")
    i2=input("What the Second number? ")
    print ("The sume of the number is " + str(add(i1,i2)))

if __name__ == '__main__':
    main()