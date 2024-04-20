# Write a program to sort 10 the given 10 numbers in ascending order using shell.



echo "Enter 10 numbers: "
read -a numbers

for (( i=0; i<10; i++ )); do
    for (( j=0; j<10-i-1; j++ )); do
        if [ ${numbers[j]} -gt ${numbers[j+1]} ]; then
            temp=${numbers[j]}
            numbers[j]=${numbers[j+1]}
            numbers[j+1]=$temp
        fi
    done
done

echo "Sorted numbers: ${numbers[@]}"
