#!/bin/bash
echo ""
echo "================================ Ways to check conditions ================================"
echo ""
# check File exist or not using "test"
if test -f test_file
then 
    echo "File exist !!!!!!!!!"
fi
# check File exist or not using "["
if [ -f test_file ]
then 
    echo "File exist !!!!!!!!!"
fi

if [ -f test_file ]; then 
    echo "File exist !!!!!!!!!"
fi


echo ""
echo "================================ String comparison ================================"
echo ""
string1="hello"
string2="hi"
string3="hello"
stringnull=""
# Compare two strings
# Compare failed bcoz compare should be resultues of string1 & string3, as like next compare.
if [ string1 == string3 ]; then 
    echo "string1 and string2 are equal !!!"
fi
if [ $string1 = $string3 ]; then 
    echo "string1 and string3 are equal !!!"
fi
if [ $string1 != $string2 ]; then 
    echo "string1 and string2 are not equal !!!"
fi
# check string is not null
if [ -n $string1 ]; then 
    echo "string1 is not null"
fi
# check string is null
if [ -z $stringnull ]; then 
    echo "stringnull is null"
fi


echo ""
echo "================================ Arithematic Expressions ================================"
echo ""
expression1=100
expression2=20
echo "expression1:: $expression1 expression2:: $expression2"
echo ""
result=`expr $expression1 + $expression2`
echo "expression1 + expression2 : $result"

result=`expr $expression1 - $expression2`
echo "expression1 - expression2 : $result"

result=`expr $expression1 \* $expression2`
echo "expression1 * expression2 : $result"

result=`expr $expression1 / $expression2`
echo "expression1 / expression2 : $result"

result=`expr $expression1 % $expression2`
echo "expression1 % expression2 : $result"

#[ expression1 -eq expression2 ]True if the expressions are equal
if [ $expression1 -eq $expression2 ]; then 
    echo "True if the expressions are equal"
fi

# [ expression1 -ne expression2 ] True if the expressions are not equal
if [ $expression1 -ne $expression2 ]; then 
    echo "True if the expressions are not equal"
fi

# [ expression1 -gt expression2 ] True if expression1 is greater than expression2
if [ $expression1 -gt $expression2 ];then 
    echo "True if expression1 is greater than expression2"
fi

# [ expression1 -ge expression2 ] True if expression1 is greater than or equal to expression2
if [ $expression1 -ge $expression2 ];then 
    echo  "True if expression1 is greater than or equal to expression2"
fi
# [ expression1 -lt expression2 ] True if expression1 is less than expression2
# [ expression1 -le expression2 ] True if expression1 is less than or equal to expression2

# [ ! expression ] True if the expression is false, and vice versa
expression1=""
if [ ! $expression1 ];then 
    echo "True if the expression is false, and vice versa"
fi

echo ""
echo "================================ File Conditions ================================"
echo ""

# [ -d file ] :: True if the file is a directory
# [ -e file ] :: True if the file exists. Note that historically the - e option has not been portable, so -f is usually used.
# [ -f file ] :: True if the file is a regular file
# [ -g file ] :: True if set-group-id is set on file
# [ -r file ] :: True if the file is readable
# [ -s file ] :: True if the file has nonzero size
# [ -u file ] :: True if set-user-id is set on file
# [ -w file ] :: True if the file is writable
# [ -x file ] :: True if the file is executable


echo ""
echo "================================ AND Lists ================================"
echo ""
touch file_one
rm -f file_two
if [ -f file_one ] && echo "hello" && [ -f file_two ] && echo "there"
then
    echo "in if"
else
    echo "in else"
fi

echo ""
echo "================================ OR Lists ================================"
echo ""
rm -f file_one
if [ -f file_one ] || echo "hello" || echo "there"
then
    echo "in if"
else
    echo "in else"
fi
exit 0