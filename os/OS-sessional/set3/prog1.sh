# Write a shell script that accepts a three-digit number and tells whether it is prime and whether it is an Armstrong number. You should check if the number entered is actually made of three digits. You should exit early if that is not the case after printing an error.

#!/bin/bash
echo "enter 3 digit number"
read n
i=0
t=$n
arm=0
while [ $t -ne 0 ]
do
  tmp=`expr $t % 10`
  tmp=`expr $tmp \* $tmp \* $tmp`
  arm=`expr $arm + $tmp`
  i=`expr $i + 1`
  t=`expr $t / 10`
done
if [ $i -eq 3 ]
then
   if [ $arm -eq $n ]
   then
	echo "armstong number"
   else
	echo "not armstong number"
   fi
   i=2
   while [ $i -lt $n ]
   do
	if [ `expr $n % $i` -eq 0 ]
	then
		break
	fi
	i=`expr $i + 1`
   done
   if [ $i -eq $n ]
   then
	echo "prime"
   else
	echo "not prime"
   fi	
else
 echo "not 3 digit number"
 exit
fi