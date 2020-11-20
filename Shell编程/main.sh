#!/bin/bash
source find.sh

max=0
maxstring=''
maxfile=''
line=0

for i in $@;do
    if [[ -f $i ]];then
        find_in_file $i
    elif [[ -d $i ]];then
        find_in_dir $i
    fi
done

line=`grep -n "$maxstring" $maxfile | cut -d ":" -f 1 | tr '\n' ' '`

printf "%s is the max string with length %d , \n in file : %s \nin lines : %s\n" ${maxstring} ${max} ${maxfile} ${line}


