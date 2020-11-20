#!/bin/bash
time=$(date "+%Y-%m-%d__%H:%M:%S")
 
eval `ps -aux --sort -%cpu -h | awk -v num=0 '{if($3 < 50) {exit} else {num++;printf("CpuProcId["num"]=%d;", $2)}} END {printf("CpuNum=%d;",num)}  '`
eval `ps -aux --sort -%mem -h | awk -v num=0 '{if($4 < 50) {exit} else {num++;printf("MemProcId["num"]=%d;", $2)}} END {printf("MemNum=%d;",num)}'`

time_stop=5;
sleep $(time_stop)

for i in ${CpuProcId[*]}:
    do echo $i;
    done
if CpuProcId[i] = 


echo -n "$time "

for i in 

