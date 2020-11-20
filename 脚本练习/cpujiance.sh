#!/bin/bash
time=$(date "+%Y-%m-%d__%H:%M:%S")
cpu_load=$(cat /proc/loadavg | cut -d " " -f 1-3)
cpu_hot=$(cat /sys/class/thermal/thermal_zone9/temp)
TIME_INTERVAL=0.5
LAST_CPU_INFO=$(cat /proc/stat | grep -w cpu | awk '{print $2,$3,$4,$5,$6,$7,$8}')
LAST_SYS_IDLE=$(echo $LAST_CPU_INFO | awk '{print $4}')
LAST_TOTAL_CPU_T=$(echo $LAST_CPU_INFO | awk '{print $1+$2+$3+$4+$5+$6+$7}')
sleep ${TIME_INTERVAL}
NEXT_CPU_INFO=$(cat /proc/stat | grep -w cpu | awk '{print $2,$3,$4,$5,$6,$7,$8}')
NEXT_SYS_IDLE=$(echo $NEXT_CPU_INFO | awk '{print $4}')
NEXT_TOTAL_CPU_T=$(echo $NEXT_CPU_INFO | awk '{print $1+$2+$3+$4+$5+$6+$7}')

#系统空闲时间
SYSTEM_IDLE=`echo ${NEXT_SYS_IDLE} ${LAST_SYS_IDLE} | awk '{print $1-$2}'`
#CPU总时间
TOTAL_TIME=`echo ${NEXT_TOTAL_CPU_T} ${LAST_TOTAL_CPU_T} | awk '{print $1-$2}'`
CPU_USAGE=`echo ${SYSTEM_IDLE} ${TOTAL_TIME} | awk '{printf "%.2f", 100-$1/$2*100}'`

echo -n "$time "
echo -n "$cpu_load "
echo -n "${CPU_USAGE}% "
echo -n "$[cpu_hot/1000]℃  "
if [[ $[cpu_hot/1000] -gt 70 ]];then
    echo "warning"
elif [[ $[cpu_hot/1000] -gt 50 ]];then
    echo "note"
else 
    echo "normal"
fi
