/*************************************************************************
	> File Name: main.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月17日 星期二 18时54分50秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<queue>
#include<chrono>
#include "thread_pool.h"
using namespace std;

//输出时加-lpthread, linux系统的锅

void func(int x, int &n) {
    n += 2;
    cout << "func : " << x << " " << n << endl;
    
    cout << "func :";
    cout << x;
    cout << " ";
    cout << n;
    cout << endl;
}

int main() {
    int n = 123;
    haizei::Task t(func, 23, ref(n));
    t.run();
    cout << n << endl;
    haizei::thread_pool tp(2);
    tp.start();
    for(int i = 0; i < 10; i++) {
        tp.add_one_task(func, i, ref(n));
    }
    cout << "add task done" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "tp stop" << endl;
    tp.stop();

    return 0;
}

