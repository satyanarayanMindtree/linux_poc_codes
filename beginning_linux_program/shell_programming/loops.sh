#!/bin/sh
echo ""
echo "===================================== for loop ===================================="
echo ""
for foo in bar fud 43
do
    echo $foo
done

for file in $(ls c*.sh); do
    echo "$file"
done


echo ""
echo "===================================== while loop ===================================="
echo ""
echo "Enter password"
read trythis
while [ "$trythis" != "secret" ]; do
    echo "Sorry, try again"
    read trythis
done

echo ""
echo "===================================== until loop ===================================="
echo ""
until who | grep "$1" > /dev/null
do
    sleep 2
done
# now ring the bell and announce the expected user.
echo -e ‘\a’
echo “**** $1 has just logged in ****“

exit 0
