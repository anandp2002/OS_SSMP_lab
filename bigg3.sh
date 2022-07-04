echo :

echo " Enter 3 numbers"
read a
read b
read c
if [ $a -gt $b ] && [ $a -gt $c ]
then
echo " $a is Biggest "




else if [ $b -gt $c ]
then
echo " $b is Biggest "



else
echo " $c is Biggest "
fi
fi


  
