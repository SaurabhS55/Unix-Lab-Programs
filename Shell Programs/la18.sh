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
    if [ $ch = 1 ]
    then
        echo "Addition= $(($no1+$no2))"
    fi
    if [ $ch = 2 ]
    then
        echo "Addition= $(($no1-$no2))"
    fi
    if [ $ch = 3 ]
    then
        echo "Addition= $(($no1*$no2))"
    fi
    if [ $ch = 4 ]
    then
        echo "Addition= $(($no1/$no2))"
    fi
    echo "Do you want to continue?"
    read i
    if [ $i != "y" ]
    then
        exit
    fi
done