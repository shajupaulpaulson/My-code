#!/bin/bash
#set -xv
rows=63
coloumns=101

#filling lines
j=0
while [ $j -lt 101 ]
do
	string+=$'-'
	j=`expr $j + 1`
done
#echo "$string"
i=0
while [ $i -lt 63 ] 
do

	output[$i]=$string
	i=`expr $i + 1`
done
#for i in ${output[@]}; do echo $i; done
#first Y
rows=`expr $rows + 1`
split=`expr $rows / 2`
rows=`expr $rows - 1`
i=1
coloumns=`expr $coloumns + 1`
rowcoloumn=1
while [ $split -ne 0 ]
do
	div=`expr $split / 2`
	mainiter=0
	j=`expr $i + 1`
	char=`expr $coloumns / $j`
	while [ $mainiter -lt $split ]
	do
		iter=0
		arraypos=`expr $rows - $rowcoloumn`
		if [ $arraypos -le 0 ]
   		then
			break
		fi
		while [ $iter -lt $i ]
		do
			output[$arraypos]=`echo ${output[$arraypos]} | sed s/./1/$char`
			iter=`expr $iter + 1`
		done
		rowcoloumn=`expr $rowcoloumn + 1`
	done
	i=`expr $i + 1`
	mainiter=0
	while [ $mainiter -lt $split ]
	do
		iter=0
		delta=`expr $mainiter \* 2`
		j=1
		x=`expr $char - $j`
		arraypos=`expr $rows - $rowcoloumn`
		if [ $arraypos -le 0 ]
   		then
			break
		fi
		while [ $iter -lt $i ]
		do
			output[$arraypos]=`echo ${output[$arraypos]} | sed s/./1/$x`
			iter=`expr $iter + 1`
			x=`expr $x + $delta`
		done
		rowcoloumn=`expr $rowcoloumn + 1`
	done
	i=`expr $i + 1`
	split=`expr $split / 2`
done
splity=`expr $firsty / 2`
splitbelow=`expr $rows - $splity`
char=`expr $coloumns / 2`
char=`expr $char + 1`

for i in ${output[@]}; do echo $i; done
#echo "${output[*]}"
