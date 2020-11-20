/*************************************************************************
	> File Name: logger.h
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月19日 星期四 19时31分49秒
 ************************************************************************/
#ifndef _LOGGER_H
#define _LOGGER_H

#include<iostream>
#include<sstream>
#include<mutex>
#include<sys/time.h>
#include<time.h>
#include<map>
#include<unistd.h>
#include<string>
#include<stdio.h>
//ostringstream //输出到字符串中

#define LOG_TRACE(level) haizei::haizei_log(__FILE__, __func__,__LINE__, level)
#define LOG_INFO LOG_TRACE(haizei::LogLevel::INFO)
#define LOG_DEBUG LOG_TRACE(haizei::LogLevel::DEBUG)
#define LOG_WARN LOG_TRACE(haizei::LogLevel::WARN)
#define LOG_ERROR LOG_TRACE(haizei::LogLevel::ERROR)
#define LOG_SET(levels) haizei::Logger::set_level(levels)
namespace haizei {

class LogLevel {   
public :
    static const int INFO;
    static const int DEBUG;
    static const int WARN;
    static const int ERROR;
};

    const int LogLevel::INFO = 1;
    const int LogLevel::DEBUG = 2;
    const int LogLevel::WARN = 4;
    const int LogLevel::ERROR = 8;

std::map<int, std::string> LogLevelStr = {
    {LogLevel::INFO, "INFO"}, 
    {LogLevel::DEBUG, "DEBUG"}, 
    {LogLevel::WARN, "WARN"}, 
    {LogLevel::ERROR, "ERROR"},
};

class Logger {

class LoggerStream : public std::ostringstream {
public :
        LoggerStream(const char *file_name, const char *func_name ,int line_no, Logger &raw_obj, int l) :raw_obj(raw_obj), line_no(line_no), flag(1) {
        std::ostringstream &now = *this;
        now << "[" << file_name << "  project] ";
        now_time();
        now << " [" << func_name << "] ";
        now << " ["<< LogLevelStr[l] << "] ";
        flag = Logger::logger_level_conf & l; //判断是否是可以输出的，二进制
    }

        LoggerStream(const LoggerStream &ls) : raw_obj(ls.raw_obj){}

  /*template<typename T>
    LoggerStream &operator<<(T &&a) {
        std::cout << "logger stream output : " << a << std::endl;
        this->std::ostringstream::operator<<(std::forward<T>(a)); //使用forward固定参数类型
        return *this;
    }
    */

    ~LoggerStream() { //在析构时直接输出
        if(flag) outputs();
    }
private :
    void outputs() {
        std::unique_lock<std::mutex> lock(raw_obj.m_mutex);
        std::ostringstream &now = *this;
        now << " (" << line_no << ")";
        std::cout << this->str() << std::endl;  //输出成string 类型
        std::cout.flush();
        return ;
    } 
    

    void now_time() {
        time_t times;
        time (&times);
        char arr[100];
        strftime(arr, sizeof(arr), " %Y-%m-%d %H:%M:%S", localtime(&times));
        std::ostringstream &now =*this;
        now << arr;
    }

    int line_no;
    Logger &raw_obj;
    int flag;
};
public :
    LoggerStream operator()(const char *file_name, const char *func_name, int line_no, int l) {
        return LoggerStream(file_name, func_name, line_no, *this, l);
    }
    static void set_level(int levels) {
        Logger::logger_level_conf = levels;
        return ;
    }
private :
    std::mutex m_mutex;
    static int logger_level_conf; //四位二进制
};

Logger haizei_log;
int Logger::logger_level_conf = 15;

}


#endif

