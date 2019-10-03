#!/bin/bash
#set -xv

pattern1(){


	j=15
	for ((i = 47; i >31;i--))
	do
		f=`expr 50 - $j - 1`
		l=`expr 50 + $j `
		temp=`echo $line | sed s/_/1/$f  | sed s/_/1/$l`
		echo "${temp}" #>> $tempfile
		j=`expr $j - 1 `
	done
	temp=`echo $line | sed s/_/1/50 `
	for ((i = $rows; i >47;i--))
	do
		echo "${temp}" #>> $tempfile
	done
}

pattern2(){

	j=15
	f=`expr 50 - $j - 1`
	l=`expr 50 + $j `
	j2=7
	for ((i = 23; i >15;i--))
	do
		f1=`expr $f - $j2 - 1`
		l1=`expr $f + $j2 `
		f2=`expr $l - $j2 - 2`
		l2=`expr $l + $j2 - 1`
		temp=`echo $line | sed s/_/1/$f1  | sed s/_/1/$l1 | sed s/_/1/$f2  | sed s/_/1/$l2`
		echo "${temp}" #>> $tempfile
		j2=`expr $j2 - 1 `
	done
	
	temp=`echo $line | sed s/_/1/$f  | sed s/_/1/$l`
	for ((i = 31; i >23;i--))
	do	
		echo "${temp}" #>> $tempfile
	done
}

pattern3(){

	j=15
	f=`expr 50 - $j - 1`
	l=`expr 50 + $j `
	j2=7
	f1=`expr $f - $j2 - 1`
	l1=`expr $f + $j2 `
	f2=`expr $l - $j2 - 2`
	l2=`expr $l + $j2 - 1`
	j3=3
	for ((i = 11; i >7;i--))
	do
		f11=`expr $f1 - $j3 - 1`
		l12=`expr $f1 + $j3 `		
		f21=`expr $l1 - $j3 - 2`
		l22=`expr $l1 + $j3 - 1`
		f31=`expr $f2 - $j3 - 3`
		l32=`expr $f2 + $j3 - 2`
		f41=`expr $l2 - $j3 - 4`
		l42=`expr $l2 + $j3 - 3`
		temp=`echo $line | sed s/_/1/$f11  | sed s/_/1/$l12 | sed s/_/1/$f21  | sed s/_/1/$l22 | sed s/_/1/$f31  | sed s/_/1/$l32 | sed s/_/1/$f41  | sed s/_/1/$l42`
		echo "${temp}" #>> $tempfile
		j3=`expr $j3 - 1 `
	done
	temp=`echo $line | sed s/_/1/$f1  | sed s/_/1/$l1 | sed s/_/1/$f2  | sed s/_/1/$l2`
	for ((i = 15; i >11;i--))
	do
		echo "${temp}" #>> $tempfile
	done
}

pattern4(){

	j=15
	f=34
	l=65
	j2=7
	f1=26
	l1=41
	f2=56
	l2=71
	j3=3
	f11=22
	l12=29		
	f21=36
	l22=43
	f31=50
	l32=57
	f41=64
	l42=71
	j4=1
	for ((i = 5; i >3;i--))
	do
		f111=`expr $f11 - $j4 - 1`
		l111=`expr $f11 + $j4 `		
		f121=`expr $l12 - $j4 - 2`
		l122=`expr $l12 + $j4 - 1`
		f211=`expr $f21 - $j4 - 3`
		l212=`expr $f21 + $j4 - 2`
		f221=`expr $l22 - $j4 - 4`
		l222=`expr $l22 + $j4 - 3`
		f311=`expr $f31 - $j4 - 5`
		l312=`expr $f31 + $j4 - 4`		
		f321=`expr $l32 - $j4 - 6`
		l322=`expr $l32 + $j4 - 5`
		f411=`expr $f41 - $j4 - 7`
		l412=`expr $f41 + $j4 - 6`
		f421=`expr $l42 - $j4 - 8`
		l422=`expr $l42 + $j4 - 7`
		temp=`echo $line | sed s/_/1/$f111  | sed s/_/1/$l111 | sed s/_/1/$f121  | sed s/_/1/$l122 | sed s/_/1/$f211  | sed s/_/1/$l212 | sed s/_/1/$f221  | sed s/_/1/$l222 | sed s/_/1/$f311  | sed s/_/1/$l312 | sed s/_/1/$f321  | sed s/_/1/$l322 | sed s/_/1/$f411  | sed s/_/1/$l412 | sed s/_/1/$f421  | sed s/_/1/$l422`
		echo "${temp}" #>> $tempfile
		j4=`expr $j4 - 1 `
	done

	temp=`echo $line | sed s/_/1/$f11  | sed s/_/1/$l12 | sed s/_/1/$f21  | sed s/_/1/$l22 | sed s/_/1/$f31  | sed s/_/1/$l32 | sed s/_/1/$f41  | sed s/_/1/$l42`
	for ((i = 7; i >5;i--))
	do
		echo "${temp}" #>> $tempfile
	done
}

pattern5(){
	j=15
	f=34
	l=65
	j2=7
	f1=26
	l1=41
	f2=56
	l2=71
	j3=3
	f11=22
	l12=29		
	f21=36
	l22=43
	f31=50
	l32=57
	f41=64
	l42=71
	j4=1
	f111=20
	l111=23
	f121=26
	l122=29
	f211=32
	l212=35
	f221=38
	l222=41
	f311=44
	l312=47
	f321=50
	l322=53
	f411=56
	l412=59
	f421=62
	l422=65

	f1111=19
	l1111=20
	f1112=21
	l1112=22
	f1211=23
	l1212=24
	f1221=25
	l1222=26

	f2111=27
	l2112=28
	f2121=29
	l2122=30
	f2211=31
	l2212=32
	f2221=33
	l2222=34

	f3111=35
	l3112=36
	f3121=37
	l3122=38
	f3211=39
	l3212=40
	f3221=41
	l3222=42

	f4111=43
	l4112=44
	f4121=45
	l4122=46
	f4211=47
	l4212=48
	f4221=49
	l4222=50


	temp=`echo $line | sed s/_/1/$f1111  | sed s/_/1/$l1111 | sed s/_/1/$f1112  | sed s/_/1/$l1112 | sed s/_/1/$f1211  | sed s/_/1/$l1212 | sed s/_/1/$f1221  | sed s/_/1/$l1222 | sed s/_/1/$f2111  | sed s/_/1/$l2112 | sed s/_/1/$f2121  | sed s/_/1/$l2122 | sed s/_/1/$f2211  | sed s/_/1/$l2212 | sed s/_/1/$f2221  | sed s/_/1/$l2222 | sed s/_/1/$f3111  | sed s/_/1/$l3112 | sed s/_/1/$f3121  | sed s/_/1/$l3122 | sed s/_/1/$f3211  | sed s/_/1/$l3212 | sed s/_/1/$f3221  | sed s/_/1/$l3222 | sed s/_/1/$f4111  | sed s/_/1/$l4112 | sed s/_/1/$f4121  | sed s/_/1/$l4122 | sed s/_/1/$f4211  | sed s/_/1/$l4212 | sed s/_/1/$f4221  | sed s/_/1/$l4222`
	echo "${temp}" #>> $tempfile


	temp=`echo $line | sed s/_/1/$f111  | sed s/_/1/$l111 | sed s/_/1/$f121  | sed s/_/1/$l122 | sed s/_/1/$f211  | sed s/_/1/$l212 | sed s/_/1/$f221  | sed s/_/1/$l222 | sed s/_/1/$f311  | sed s/_/1/$l312 | sed s/_/1/$f321  | sed s/_/1/$l322 | sed s/_/1/$f411  | sed s/_/1/$l412 | sed s/_/1/$f421  | sed s/_/1/$l422`
	echo "${temp}" #>> $tempfile

	for ((i = 5; i >3;i--))
	do
		temp=`echo $line | sed s/_/1/$f111  | sed s/_/1/$l111 | sed s/_/1/$f121  | sed s/_/1/$l122 | sed s/_/1/$f211  | sed s/_/1/$l212 | sed s/_/1/$f221  | sed s/_/1/$l222 | sed s/_/1/$f311  | sed s/_/1/$l312 | sed s/_/1/$f321  | sed s/_/1/$l322 | sed s/_/1/$f411  | sed s/_/1/$l412 | sed s/_/1/$f421  | sed s/_/1/$l422`
		echo "${temp}" #>> $tempfile
		j4=`expr $j4 - 1 `
		f111=`expr $f11 - $j4 - 1`
		l111=`expr $f11 + $j4 `		
		f121=`expr $l12 - $j4 - 2`
		l122=`expr $l12 + $j4 - 1`
		f211=`expr $f21 - $j4 - 3`
		l212=`expr $f21 + $j4 - 2`
		f221=`expr $l22 - $j4 - 4`
		l222=`expr $l22 + $j4 - 3`
		f311=`expr $f31 - $j4 - 5`
		l312=`expr $f31 + $j4 - 4`		
		f321=`expr $l32 - $j4 - 6`
		l322=`expr $l32 + $j4 - 5`
		f411=`expr $f41 - $j4 - 7`
		l412=`expr $f41 + $j4 - 6`
		f421=`expr $l42 - $j4 - 8`
		l422=`expr $l42 + $j4 - 7`
	done

	temp=`echo $line | sed s/_/1/$f11  | sed s/_/1/$l12 | sed s/_/1/$f21  | sed s/_/1/$l22 | sed s/_/1/$f31  | sed s/_/1/$l32 | sed s/_/1/$f41  | sed s/_/1/$l42`
	for ((i = 7; i >5;i--))
	do
		echo "${temp}" #>> $tempfile
	done
	for ((i = 11; i >7;i--))
	do
		temp=`echo $line | sed s/_/1/$f11  | sed s/_/1/$l12 | sed s/_/1/$f21  | sed s/_/1/$l22 | sed s/_/1/$f31  | sed s/_/1/$l32 | sed s/_/1/$f41  | sed s/_/1/$l42`
		echo "${temp}" #>> $tempfile
		j3=`expr $j3 - 1 `
		f11=`expr $f1 - $j3 - 1`
		l12=`expr $f1 + $j3 `		
		f21=`expr $l1 - $j3 - 2`
		l22=`expr $l1 + $j3 - 1`
		f31=`expr $f2 - $j3 - 3`
		l32=`expr $f2 + $j3 - 2`
		f41=`expr $l2 - $j3 - 4`
		l42=`expr $l2 + $j3 - 3`
	done
	temp=`echo $line | sed s/_/1/$f1  | sed s/_/1/$l1 | sed s/_/1/$f2  | sed s/_/1/$l2`
	for ((i = 15; i >11;i--))
	do
		echo "${temp}" #>> $tempfile
	done	

	for ((i = 23; i >15;i--))
	do

		temp=`echo $line | sed s/_/1/$f1  | sed s/_/1/$l1 | sed s/_/1/$f2  | sed s/_/1/$l2`
		echo "${temp}" #>> $tempfile
		j2=$(( $j2 - 1 ))
		f1=$(( $f - $j2 - 1 ))
		l1=$(( $f + $j2 ))
		f2=$(( $l - $j2 - 2 ))
		l2=$(( $l + $j2 - 1 ))
	done
	
	temp=`echo $line | sed s/_/1/$f  | sed s/_/1/$l`
	for ((i = 31; i >23;i--))
	do	
		echo "${temp}" #>> $tempfile
	done

	for ((i = 47; i >31;i--))
	do
		temp=`echo $line | sed s/_/1/$f  | sed s/_/1/$l`
		echo "${temp}" #>> $tempfile
		j=$(( j - 1 ))
		f=$(( 50 - $j - 1 ))
		l=$(( 50 + $j ))
	done
	for ((i = $rows; i >47;i--))
	do
		#temp=`echo $line | sed s/_/1/50 `
		echo "${line:0:49}1${line:51}" #>> $tempfile
	done
}

rows=63
coloumns=100
#tmpfile=$(mktemp)
line=""
read var1

for ((j = 0;j < $coloumns;j++))
do
	line+="_" 
done
#echo $line >> 
if [[ $var1 -eq 1 ]]; then
	for ((i = 31; i >0;i--))
	do
		echo "${line}" #>> 
	done
	pattern1 

elif [[ $var1 -eq 2 ]]; then
	for ((i = 15; i >0;i--))
	do
		echo "${line}" #>> 
	done
	pattern2 
	pattern1 

elif [[ $var1 -eq 3 ]]; then
	for ((i = 7; i >0;i--))
	do
		echo "${line}" #>> 
	done
	pattern3 
	pattern2 
	pattern1 

elif [[ $var1 -eq 4 ]]; then
	for ((i = 3; i >0;i--))
	do
		echo "${line}" #>> 
	done
	pattern4 
	pattern3 
	pattern2 
	pattern1 

elif [[ $var1 -eq 5 ]]; then
	for ((i = 1; i >0;i--))
	do
		echo "${line}" #>> 
	done
	pattern5 
	#pattern4 
	#pattern3 
	#pattern2 
	#pattern1 

else
	for ((i = $rows; i >0;i--))
	do
		echo "${line}" #>> 
	done
fi
#cat 
#rm ${tmpfile}


