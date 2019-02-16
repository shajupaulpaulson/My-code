#!/bin/bash
#set -xv
rows=63
coloumns=101

#filling lines
j=0
while [ $j -lt 100 ]
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
firsty=`expr $rows / 2`
splity=`expr $firsty / 2`
splitbelow=`expr $rows - $splity`
char=`expr $coloumns / 2`
char=`expr $char + 1`
splitbelow=`expr $splitbelow - 1`
while [ $splitbelow -lt $rows ]
do
	output[$splitbelow]=`echo ${output[$splitbelow]} | sed s/./1/$char `
	splitbelow=`expr $splitbelow + 1`

done
#splitting Y
splitbelow=`expr $rows - $splity`
splitbelow=`expr $splitbelow - 2`
i=1
lefty=0
righty=0
echo "$splity"
echo "$splitbelow"
while [ $firsty -lt $splitbelow ]
do	
	delta=`expr $i \* 2`
	#delta=`expr $delta + 1`
	lefty=`expr $char - $i`
	righty=`expr $lefty + $delta`
	output[$splitbelow]=`echo ${output[$splitbelow]} | sed s/./1/$lefty `
	output[$splitbelow]=`echo ${output[$splitbelow]} | sed s/./1/$righty `
	splitbelow=`expr $splitbelow - 1`
	i=`expr $i + 1`
done



lengthofy2="$splity"
splity2=`expr $lengthofy2 / 2`
secondy1=`expr $splitbelow - $splity2`

while [ $secondy1 -lt $splitbelow ]
do
	output[$splitbelow]=`echo ${output[$splitbelow]} | sed s/./1/$lefty `
	output[$splitbelow]=`echo ${output[$splitbelow]} | sed s/./1/$righty `
	splitbelow=`expr $splitbelow - 1`
done

lefty1=0
righty1=0
lefty2=0
righty2=0

i=0
secondy1=`expr $splitbelow - $splity2`
secondy1=`expr $secondy1 - 1`
while [ $secondy1 -lt $splitbelow ]
do	
	delta=`expr $i \* 2`
	#delta=`expr $delta + 1`
	lefty1=`expr $lefty - $i`
	righty1=`expr $lefty1 + $delta`
	lefty2=`expr $righty - $i`
	righty2=`expr $lefty2 + $delta`
	output[$splitbelow]=`echo ${output[$splitbelow]} | sed s/./1/$lefty1 | sed s/./1/$righty1 | sed s/./1/$lefty2 | sed s/./1/$righty2`
	splitbelow=`expr $splitbelow - 1`
	i=`expr $i + 1`
done

splity2=`expr $splity2 / 2`
secondy1=`expr $splitbelow - $splity2`
secondy1=`expr $secondy1 - 1`
while [ $secondy1 -lt $splitbelow ]
do
	output[$splitbelow]=`echo ${output[$splitbelow]} | sed s/./1/$lefty1 | sed s/./1/$righty1 | sed s/./1/$lefty2 | sed s/./1/$righty2 `
	splitbelow=`expr $splitbelow - 1`
done


leftx1=0
rightx1=0
leftx2=0
rightx2=0
leftx3=0
rightx3=0
leftx4=0
rightx4=0
i=0
secondy1=`expr $splitbelow - $splity2`
secondy1=`expr $secondy1 - 1`
while [ $secondy1 -lt $splitbelow ]
do	
	delta=`expr $i \* 2`
	#delta=`expr $delta + 1`
	leftx1=`expr $lefty1 - $i`
	rightx1=`expr $leftx1 + $delta`
	leftx2=`expr $righty1 - $i`
	rightx2=`expr $leftx2 + $delta`
	leftx3=`expr $lefty2 - $i`
	rightx3=`expr $leftx3 + $delta`
	leftx4=`expr $righty2 - $i`
	rightx4=`expr $leftx4 + $delta`
	output[$splitbelow]=`echo ${output[$splitbelow]} | sed s/./1/$leftx1 | sed s/./1/$rightx1 | sed s/./1/$leftx2 | sed s/./1/$rightx2 | sed s/./1/$leftx3 | sed s/./1/$rightx3 | sed s/./1/$leftx4 | sed s/./1/$rightx4`
	splitbelow=`expr $splitbelow - 1`
	i=`expr $i + 1`
done
splity2=`expr $splity2 / 2`
secondy1=`expr $splitbelow - $splity2`
secondy1=`expr $secondy1 - 1`

while [ $secondy1 -lt $splitbelow ]
do
	output[$splitbelow]=`echo ${output[$splitbelow]} | sed s/./1/$leftx1 | sed s/./1/$rightx1 | sed s/./1/$leftx2 | sed s/./1/$rightx2 | sed s/./1/$leftx3 | sed s/./1/$rightx3 | sed s/./1/$leftx4 | sed s/./1/$rightx4 `
	splitbelow=`expr $splitbelow - 1`
done

for i in ${output[@]}; do echo $i; done
#echo "${output[*]}"
