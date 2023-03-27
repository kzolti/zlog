#include "logimpl.h"

#include <iomanip>
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>



void log(LogLevel level, const std::string& message,
         const char* file, int line, const char* function)
{
    // Ha nem debug akkor return
#ifdef DEBUG
#else
    if (level == LogLevel::_DEBUG ) {
        return;
    }
#endif

    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    auto t = std::chrono::system_clock::to_time_t(now);
    auto tm = std::localtime(&t);
    std::stringstream ss;
    ss << std::put_time(tm, "%Y.%m.%d %H:%M:%S.") << std::setfill('0') << std::setw(3) << ms % 1000 << " "; //std::put_time(tm, "%Y-%m-%d %H:%M:%S");
    std::string timeStr = ss.str();

    const char* color = "";
    const char* levelStr = "";
    switch (level) {
           case LogLevel::_SUCCESS:
               color = "\033[32m";
               levelStr = "SUCCESS";
               break;
           case LogLevel::_INFO:
               color = "\033[34m";
               levelStr = "INFO   ";
               break;
           case LogLevel::_WARNING:
               color = "\033[33m";
               levelStr = "WARNING";
               break;
           case LogLevel::_ERROR:
               color = "\033[31m";
               levelStr = "ERROR  ";
               break;
           case LogLevel::_DEBUG:
               color = "\033[35m";
               levelStr = "DEBUG  ";
               break;
           case LogLevel::_FATAL:
               color = "\033[31m";
               levelStr = "FATAL  ";
               break;
           default:
               break;
       }
    if (level == LogLevel::_ERROR || level == LogLevel::_FATAL){
        fprintf(stdout, "%s%s %s %s\033[0m %s %s:%d \n", timeStr.c_str(), color, levelStr, message.c_str(), file, function,line);
        fprintf(stderr, "%s %s %s %s %s:%d \n", timeStr.c_str(), levelStr, message.c_str(), file, function,line);
    }else{
        fprintf(stdout, "%s%s %s %s\033[0m %s %s:%d \n", timeStr.c_str(), color, levelStr, message.c_str(), file, function,line);
    }
        if (level == LogLevel::_FATAL) {
            exit(EXIT_FAILURE);
        }

}


