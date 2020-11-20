#!/bin/bash
time=$(date "+%Y-%m-%d__%H:%M:%S")

vector=$(df -h -T -x tmpfs -x devtmpfs -x squashfs -m | tail -n +2 | head -n 1 | awk '{printf("%d"), $3}')

vector2=$(df -h -T -x tmpfs -x devtmpfs -x squashfs -m | tail -n +3 | head -n 1 | awk '{printf("%d"), $3}')

Ppath=$(df -h -T -x tmpfs -x devtmpfs -x squashfs -m | tail -n +2 | head -n 1 | awk '{printf("%s"), $7}')

Ppath2=$(df -h -T -x tmpfs -x devtmpfs -x squashfs -m | tail -n +3 | head -n 1 | awk '{printf("%s"), $7}')

remain=$(df -h -T -x tmpfs -x devtmpfs -x squashfs -m | tail -n +2 | head -n 1 | awk '{printf("%d"), $5}')

remains=$(df -h -T -x tmpfs -x devtmpfs -x squashfs -m | tail -n +2 | head -n 1 | awk '{printf("%d"), $6}')

remain2=$(df -h -T -x tmpfs -x devtmpfs -x squashfs -m | tail -n +3 | head -n 1 | awk '{printf("%d"), $5}')

remains2=$(df -h -T -x tmpfs -x devtmpfs -x squashfs -m | tail -n +3 | head -n 1 | awk '{printf("%d"), $6}')


echo -n "$time 1 "
echo -n "$Ppath "
echo -n "$vector "
echo -n "$remain "
echo "$remains%"
echo -n "$time 1 "
echo -n "$Ppath2 "
echo -n "$vector2 "
echo -n "$remain2 "
echo "$remains2%"




