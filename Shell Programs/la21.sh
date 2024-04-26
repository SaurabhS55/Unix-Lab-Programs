# Write a program to sort 10 the given 10 numbers in ascending order using shell.



echo "Enter 5 elements"
read -a num
for (( i=0; i<5; i++ )); do
    for (( j=0; j<5-i-1; j++ )); do
        if [ ${num[j]} -gt ${num[j+1]} ]; then
            t=${num[j]}
            num[j]=${num[j+1]}
            num[j+1]=$t
        fi
    done
done

echo "Sorted array"
echo ${num[@]}
