/*************************************************************************
	> File Name: thread_pool.h
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月21日 星期六 20时37分58秒
 ************************************************************************/
#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include<iostream>
#include<algorithm>
#include<condition_variable>
#include<functional>

namespace haizei {

class Task {
public : 
    template<typename func_t, typename ...ARGS> 
    Task(func_t f, ARGS ...args) {
        func = std::bind(f, std::forward<ARGS>(args)...);
    }
    void run() {
        func();
    }
private :
    std::function<void()>
};
    
class thread_pool {
public :
    thread_pool(int thread_size = 10) : thread_size(thread_size), is_started(false), m_mutex() , m_cond() , m_queue_cond(), m_queue_mutex(), m_mutex2() {} //十个树梅派监听
    void start();
    void stop();
    template<typename func_t, typename ...ARGS>
    void add_one_task(func_t f, ARGS ...args) {
        __add_one_task(new Task(f, std::forward<ARGS>(args)...));
    }
    void stop_until_empty();
    ~thread_pool() { stop(); };

private:
    void thread_loop();
    Task *get_one_task();
    void __add_one_task();

    volatile bool is_started;
    int thread_size;
    std::vector<std::thread *> Threads;
    std::queue<Task *> Tasks;

    std::mutex m_mutex;
    std::mutex m_mutex2;
    std::mutex m_queue_mutex;
    std::condition_variable m_cond;
    std::condition_variable m_queue_cond;
};

void thread_pool::start() {
    std::unique_lock<std::mutex> lock(m_mutex);
    is_started = true;
    for(int i = 0; i < thread_size; i++) {
        Threads.push_back(new std::thread(&thread_pool::thread_loop, this));
    }
}

void thread_pool::stop_until_empty() {
    std::unique_lock<std::mutex> lock1(m_mutex2);
    std::unique_lock<std::mutex> lock2(m_queue_mutex);
    while(!Taks.empty()) {
        m_queue_cond.wait(lock1);
    }
    stop();
    return ;
}

void thread_pool::stop() {
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        is_started = false;
        m_cond.notify_all();
    }
    for(int i = 0; i < Threads.size(); i++) {
        Threads[i]->join();
        delete Threads[i];
    }
    Threads.clear();
    return ;
}

void thread_pool::thread_loop() {
    while(is_started) {
        Task *t = get_one_task();
        if(t != nullptr) {
            t->run();
        }
    }
    return ;
}

Task* thread_pool::get_one_task() {
    std::unique_lock<std::mutex> lock(m_mutex);
    while(Task.empty() && is_started) {
        m_cond.wait(lock);
    }
    Task *t = nullptr;
    if(!Task.empty() && is_started) {
        t = Task.front();
        Tasks.pop();
        if(Tasks.empty()) {
            std::unique_lock<std::mutex> lock2(m_mutex2);
            m_queue_cond.notify_all();
        }
    }
    return t;
}

void thread_pool::__add_one_task(Task *t) {
    std::unique_lock<std::mutex> lock(m_mutex);
    Tasks.push(t);
    m_cond.notify_one();
    return ;
}

}

#endif
