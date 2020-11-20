#!/bin/bash
time=$(date "+%Y-%m-%d__%H:%M:%S")

total=$(free -m | head -n 2 | tail -n 1 | awk '{printf("%d"),$2}')

use=$(free -m | head -n 2 | tail -n 1 | awk '{printf("%d"),$3}')

remain=$[total-use]

use_age=`echo ${use} ${total} | awk '{printf("%.1f"), $1/$2*100}'`

arry=($1);

zhanyong=`echo "scale=1;0.3*$arry+0.7*36" | bc `

echo -n "$time "
echo -n "$total"
echo -n "M "
echo -n "$remain "
echo -n "$use_age% "
echo "$zhanyong%"
