#!/usr/bin/env python
# coding=utf-8
sum = 0;
def solve(num):
    for i in range(2, num//2+1):
        if (num % i)== 0:
            return 0;
        return 1;
    for i in range(2,100001):
        if solve(i)==1:
            sum += i
print(sum)
   

