#!/bin/bash
#max

#maxstring

#maxfile

#line

function fliter(){
    types="png jpeg avi pdf exe out"
    file_name=`basename $1`
    file_type=`echo ${filename} | tr '.' '\n' | tail -1`
    for i in ${types};do
        if [[ $i == ${file_type} ]];then
            return 1
        fi
    done

    file $i | grep -q -w "text" 2>/dev/null

    if [[ $? -ne 0 ]];then
        return 1
    fi

    return 0
}

function find_in_file(){
    fliter $i
    if [[ $? -eq 1]];thenn
        return
    fi
    words=`cat $1 | tr -s -c 'A-Za-z' "\n"`
    for i in ${words};do
        t_len=`echo ${#i}`
        if [[ ${t_len} -gt ${max} ]];then
            max=${t_len}
            maxstring=$i
            maxfile=$1
        fi
    done
}


function find_in_dir(){
    for i in `ls -A $1`;do
        if [[ -d $1/$i ]];then
            find_in_dir $1/$i
        else
            find_in_file $1/$i
        fi
    done
} 
