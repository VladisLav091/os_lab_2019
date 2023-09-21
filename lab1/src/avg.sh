count=0
sum=0
while read -r num
do
  ((count++))
  sum=$(echo "$sum + $num" | bc)
done < numbers.txt
echo "scale=2; $sum / $count" | bc -l