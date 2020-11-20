/*************************************************************************
	> File Name: singleton.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月24日 星期二 19时54分40秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<mutex>
#include<cstdio>
using namespace std;

class HttpServer {
public :
    static HttpServer *getInstance() { //多线程下的互斥锁
        if(instance == nullptr) { //双重验证是否需要初始化，提升效率
            std::unique_lock<std::mutex> lock(m_mutex); // 懒汉模式
            if(instance == nullptr) { 
                instance = new HttpServer();
            }
        }
        return instance;
    }
    

private :
    static HttpServer *instance;
    static std::mutex m_mutex;
    HttpServer() {};
    HttpServer(const HttpServer &) = delete;
    ~HttpServer() {}  //需要设置虚构函数为私有，这样就不能删除
};

//HttpServer *HttpServer::instance = new HttpServer(); //饿汉模式
HttpServer *HttpServer::instance = nullptr;
std::mutex HttpServer::m_mutex;

int main() {
    HttpServer *t1 = HttpServer::getInstance();
    delete t1;
    HttpServer *t2 = HttpServer::getInstance();
     
    cout << t1 << " " << t2 << endl; //两者一样，同一个对象

    return 0;
}


