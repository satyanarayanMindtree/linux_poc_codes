#!/bin/sh

echo ""
echo "================================ Case - I:: simple case ================================"
echo ""
echo "Is it morning? Please answer yes or no"
read timeofday
case "$timeofday" in
    yes) echo "Good Morning";;
    no ) echo "Good Afternoon";;
    y ) echo "Good Morning";;
    n ) echo "Good Afternoon";;
    * ) echo "Sorry, answer not recognized";;
esac


echo ""
echo "================================ Case - II:: Putting Patterns Together ================================"
echo ""
echo "Is it morning? Please answer yes or no"
read timeofday
case "$timeofday" in
yes | y | Yes | YES ) echo "Good Morning";;
n* | N* ) echo "Good Afternoon";;
* ) echo "Sorry, answer not recognized";;
esac


echo ""
echo "================================ Case - III:: executing multiple statements ================================"
echo ""
echo "Is it morning? Please answer yes or no"
read timeofday
case "$timeofday" in
[yY]*)  echo "Good Morning"
        echo "Up bright and early this morning";;
n* | N* ) echo "Good Afternoon";;
* ) echo "Sorry, answer not recognized";;
esac


exit 0