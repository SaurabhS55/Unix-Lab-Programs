# Write a program to implement shell script for calculator.

echo "Enter no1"
read no1
echo "Enter no2"
read no2
i="y"
while [ $i = "y" ]
do
    echo "1.Addition"
    echo "2.Subtraction"
    echo "3.Multiplication"
    echo "4.Division"
    echo "Enter your choice"
    read ch
    case $ch in
        1)sum=`expr $no1 + $no2`
        echo "Sum="$sum;;
        2)sub=`expr $no1 - $no2`
        echo "Sub="$sub;;
        3)mul=`expr $no1 \* $no2`
        echo "Mul="$mul;;
        4)div=`expr $no1 / $no2`
        echo "Div="$div;;
        *)echo "Invalid choice";;
    esac
    echo "Do you want to continue?"
    read i
    if [ $i != "y" ]
    then
        exit
    fi
done