#!/bin/bash

check(){
	TEST=$1
	ret=`echo $TEST | sed  -n 's/^[0-9]*$//p' | wc -c`
	return $ret
}

echo "Program to Add, Sub, Mul and divide using shell script"
echo "Please enter first number :"
read num1
echo "Please enter Second number :"
read num2
echo " Please enter +, -, *, / or %"
read symbol

check $num1
a=$?
check $num2
b=$?

if [ "$a" -eq "1" ] && [ "$b" -eq "1" ]; then
	if [ $symbol == '+' ] ;then
	  num3=`expr $num1 + $num2`
	  echo "Sum of the numbers are $num3"
	elif [ $symbol == '-' ] ;then
	  num3=`expr $num1 - $num2`
	  echo "Subtract of the numbers are $num3"
	elif [ $symbol == '*' ] ;then
	  num3=`expr $num1 * $num2`
	  echo "Multiply of the numbers are $num3"
	elif [ $symbol == '/' ] ;then
	  num3=`expr $num1 / $num2`
	  echo "Division of the numbers are $num3"
	elif [ $symbol == '%' ] ;then
	  num3=`expr $num1 % $num2`
	  echo "Reminder is $num3"
	else
	 echo "Wrong symbol"
	fi
else
	echo "one or both not numbers"
fi


