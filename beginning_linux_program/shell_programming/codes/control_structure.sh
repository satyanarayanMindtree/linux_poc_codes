#!/bin/sh
# echo ""
# echo "===================================== if-else ===================================="
# echo ""
# echo "Is it morning? Please answer yes or no"
# read timeofday
# if [ $timeofday = "yes" ]; then
#     echo "Good morning"
# else
#     echo "Good afternoon"
# fi
# exit 0


echo ""
echo "===================================== if-else ===================================="
echo ""
echo "Is it morning? Please answer yes or no"
read timeofday
if [ "$timeofday" = "yes" ]; then
    echo "Good morning"
elif [ "$timeofday" = "no" ]; then
    echo "Good afternoon"
else
    echo " sORRY INVALID option selected"
fi
exit 0

