
echo "Enter two numbers :"
read a
read b
sum=` expr $a + $b `
echo " Sum = $sum "
diff=` expr $a - $b `
echo " diff = $diff "
product=` expr $a \* $b `
echo " product = $product "
if [ $b -eq 0 ]
then
echo "Division not possible "
else
division=`expr $a / $b`
echo " Division = $division "
fi
