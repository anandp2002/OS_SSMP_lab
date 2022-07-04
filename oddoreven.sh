echo " Enter a number : "
read n
if [ $n -eq 0 ]
then
echo "Not Odd or Even"
else if [ ` expr $n % 2 ` -eq 0 ]
then
echo " Even "
else
echo " Odd "
fi
fi
