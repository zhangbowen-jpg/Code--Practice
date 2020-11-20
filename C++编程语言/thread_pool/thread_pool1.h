/*************************************************************************
	> File Name: thread_pool1.h
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月17日 星期二 20时10分10秒
 ************************************************************************/
#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include <iostream>
#include <algorithm>
#include <thread>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <functional>

namespace haizei {

class Task {
public :
    template<typename Func_T, typename ...ARGS>
    Task(Func_T f, ARGS ...args) {
        func = std::bind(f, std::forward<ARGS>(args)...);
    }
    void run() {
        func();
    }
private:
    std::function<void()> func;
};

class thread_pool {
public:        
    thread_pool(int thread_size = 5) 
    : thread_size(thread_size),
      is_started(false),
      m_mutex(),
      m_cond(m_mutex)
    {}
    void start();
    void stop();
    ~thread_pool() { stop(); }
private:
    void thread_loop();
    Task *get_one_task();

    int thread_size;
    bool is_started;
    std::vector<std::thread *> Threads;
    std::queue<Task *> Tasks;

    std::mutex m_mutex;
    std::condition_variable m_cond;
};

void thread_pool::start() {
    is_started = true;
    for (int i = 0; i < thread_size; i++) {
        Threads.push_back(new std::thread(&thread_pool::thread_loop, this));
    }
}

void thread_pool::stop() {
    is_started = false;
    for (int i = 0; i < Threads.size(); i++) {
        Threads[i]->join();
        delete Threads[i];
    }
    Threads.clear();
    return ;
}

void thread_pool::thread_loop() {
    while (is_started) {
        Task *t = get_one_task();
        if (t != nullptr) {
            t->run();
        } 
    }
    return ;
}

void thread_pool::get_one_task() {
    std::unique_lock<std::mutex> lock(m_mutex);
    while (Tasks.empty() && is_started) {
        m_cond.wait(lock);
    }
    Task *t = nullptr;
    if (!Tasks.empty() && is_started) {
        t = Tasks.front();
        Tasks.pop();
    }
    return t;
}

}

#endif

