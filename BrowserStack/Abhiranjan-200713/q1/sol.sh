#!/bin/bash
#Filename: sol.sh

var=0;

F()
{
	x=${10}
	y=${11}
	z=${x:0:1}
	if [ "$z" == "H" ] 
	then
		p=$y
	else
		p=$x
	fi	
	if [[ $p == 404 ]]; then
		var=$(expr $var + 1)
	fi
	cnt=$(expr $cnt + 1)
	array[$cnt]=$p
}

while read line           
do           
	F $line
done < sample.log

echo "Number of occurrence of error 404 = " $var 
echo ""
# echo ""
# echo "Error codes are: " ${array[@]}
#echo ""
uni=$(echo "${array[@]}" | tr ' ' '\n' | sort -u | tr '\n' ' ')
# echo $uni
# echo ""

printf "Error Codes: Number of Occurrences\n"
for u in ${uni[*]}
do
	cnt=0
	for v in ${array[*]}
	do
		if [ $v == $u ]
		then
			cnt=$(expr $cnt + 1)
		fi
	done
	printf "%d: %d\n" $u $cnt
done
