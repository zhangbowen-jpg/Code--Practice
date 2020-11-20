/*************************************************************************
	> File Name: main.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月19日 星期四 19时32分00秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstdio>
#include "logger.h"
#include "thread_pool.h"
using namespace std;

void func1(haizei::Logger &log) {
    LOG_SET(haizei::LogLevel::ERROR);
    LOG_ERROR << "there is error info" ;
    return ;
}

void func2(haizei::Logger &log) {
    LOG_SET(haizei::LogLevel::DEBUG | haizei::LogLevel::ERROR);
    LOG_INFO << "info : 1" << "2" << "3" << "4" << "5" << "6";
    LOG_DEBUG << "debug : 1" << "2" << "3" << "4" << "5" << "6";
    LOG_WARN << "warn : 1" << "2" << "3" << "4" << "5" << "6";
    LOG_ERROR << "error : 1" << "2" << "3" << "4" << "5" << "6";
    return ;
}


int main() {
    haizei::Logger log;
    haizei::thread_pool tp(10);
    tp.start();

    for(int i = 1; i <= 20; i++) {
        tp.add_one_task(func1, ref(log));
    }

    //cout << "super smart" << 123 << 456 << endl; //不安全
    std::this_thread::sleep_for(std::chrono::seconds(2));
    tp.stop();
    cout << "cout done" << endl;
    cout.flush();
    tp.start();
    for(int i = 1; i <= 20; i++) {
        tp.add_one_task(func2, ref(log)); 
    } 
    //使用函数返回值，即是右值，又是临时的对象
    std::this_thread::sleep_for(std::chrono::seconds(2));
    tp.stop();
    cout << "log done" << endl;
    return 0;
}


