#!/bin/bash
if [[ $# -eq 1 ]]; then
    gcc -D _DEBUG wechat.c ./common.c ./linklist.c -I ./ -o wechat -l pthread
else 
    gcc wechat.c ./common.c ./linklist.c -I ./ -o wechat -l pthread
fi
