
echo "enter the limit"
read n
n1=0
n2=1
var=0
echo "fibonacci series is "
echo "$n1 "
echo "$n2"
while [ $var -lt `expr $n - 2` ]
do
n3=` expr $n1 + $n2 `
n1=$n2 
n2=$n3 

var=` expr $var + 1 `
echo "$n2"
done

