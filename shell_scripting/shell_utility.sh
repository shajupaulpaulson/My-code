#!/bin/bash
#set -xv
#reading line by line
i=0
while read line
do :
	i=`expr $i + 1`
	# -ne ensure new line is not placed
	echo -ne "Line : $i "
	echo $line
done < data_file.txt

#splitting lines to tables printing coloumn 1 and 5 and last column

# wawk prinitng first second and last coloumn
cat data_file.txt | awk -F ' ' '{print $1";"$2";"$NF}'

# coverting file and filtering with grep for A-Z and printing first second
cat data_file.txt | grep '[A-Z]' | awk -F ' ' '{print $1";"$2";"$NF}'

#find the max and min coloumn available in the file
max=0
min=-1
while read line
do :
	temp=`echo $line | awk -F ' ' '{if (NF != 0) print NF}'`
	if [ $temp -gt $max ]
	then
		max=$temp
	fi
	if [ $min -eq -1 ]
	then
	   	min=$temp
	fi
	if [ $min -gt $temp ]
	then
		min=$temp
	fi
done < data_file.txt
echo "Maximum number of column is : $max" 
echo "Minimum number of column is : $min"
echo -ne "Number of Records"
awk 'END {print NR}' data_file.txt
