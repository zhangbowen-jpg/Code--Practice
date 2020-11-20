#!/bin/bash
. base.sh

max=0
maxstring=''
maxfile=''
line=0

for i in $@;do
    if [[ -f $i ]];then
        find_in_file $i
    elif [[ -d $i]];then
    find_in_dir $i
    fi
done

line`grep -n "$maxstring" $maxfile | cut -d ":" -f 1 | tr '\n' ' '`


printf "%s is the max string with length %d , \nin file : %s \nin lines : %s\n"_${maxstring}_${max}_${maxfile}_${line} 

