
echo "Enter the number to calculate factorial "
read n 
fact=1
i=1
while [ $i -le $n ]
do
fact=` expr $fact \* $i `
i=` expr $i + 1 `
done
echo "fact of $n=$fact"
