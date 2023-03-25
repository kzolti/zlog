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
#ifdef MY_DEBUG
#else
    if (level == LogLevel::DEBUG ) {
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
           case LogLevel::SUCCESS:
               color = "\033[32m";
               levelStr = "SUCCESS";
               break;
           case LogLevel::INFO:
               color = "\033[34m";
               levelStr = "INFO   ";
               break;
           case LogLevel::WARNING:
               color = "\033[33m";
               levelStr = "WARNING";
               break;
           case LogLevel::ERROR:
               color = "\033[31m";
               levelStr = "ERROR  ";
               break;
           case LogLevel::DEBUG:
               color = "\033[35m";
               levelStr = "DEBUG  ";
               break;
           case LogLevel::FATAL:
               color = "\033[31m";
               levelStr = "FATAL  ";
               break;
           default:
               break;
       }
    if (level == LogLevel::ERROR || level == LogLevel::FATAL){
        fprintf(stderr, "%s%s %s:%s %s %s:%d \033[0m\n", color, timeStr.c_str(), levelStr, message.c_str(), file, function,line);
    }else{
        fprintf(stdout, "%s%s %s:%s\033[0m %s %s:%d \n", timeStr.c_str(), color, levelStr, message.c_str(), file, function,line);
    }
        if (level == LogLevel::FATAL) {
            exit(EXIT_FAILURE);
        }

}


