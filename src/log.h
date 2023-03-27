#ifndef LOG_H
#define LOG_H

#include <string>
#include "logstream.h"
//enum class LogLevel {SUCCESS, INFO, WARNING, ERROR, DEBUG, FATAL };

//void log(LogLevel level, const std::string& message,
//         const char* file, int line, const char* function);


#define ___success LogStream(LogLevel::_SUCCESS, __FILE__, __LINE__, __FUNCTION__)
#define ___info LogStream(LogLevel::_INFO, __FILE__, __LINE__, __FUNCTION__)
#define ___warning LogStream(LogLevel::_WARNING, __FILE__, __LINE__, __FUNCTION__)
#define ___error LogStream(LogLevel::_ERROR,  __FILE__, __LINE__, __FUNCTION__)
#define ___debug LogStream(LogLevel::_DEBUG,  __FILE__, __LINE__, __FUNCTION__)
#define ___fatal LogStream(LogLevel::_FATAL,  __FILE__, __LINE__, __FUNCTION__)
#endif // LOG_H
