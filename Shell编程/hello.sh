#!/bin/bash
echo "Hello Haizei!"
echo $0
echo $1
echo $2

echo "\$*  $*"
echo "\$@  $@"
echo "\$#  $#"

ls /etc/1

if [[ $? -eq 0 ]];then
    echo "OK"
else
    echo "NO"
fi


