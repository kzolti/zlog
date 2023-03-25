#ifndef LOG_H
#define LOG_H

#include <string>
#include "logimpl.h"
//enum class LogLevel {SUCCESS, INFO, WARNING, ERROR, DEBUG, FATAL };

//void log(LogLevel level, const std::string& message,
//         const char* file, int line, const char* function);

#define ___success(message) log(LogLevel::SUCCESS, message, __FILE__, __LINE__, __FUNCTION__)
#define ___info(message) log(LogLevel::INFO, message, __FILE__, __LINE__, __FUNCTION__)
#define ___warning(message) log(LogLevel::WARNING, message, __FILE__, __LINE__, __FUNCTION__)
#define ___error(message) log(LogLevel::ERROR, message, __FILE__, __LINE__, __FUNCTION__)
#define ___debug(message) log(LogLevel::DEBUG, message, __FILE__, __LINE__, __FUNCTION__)
#define ___fatal(message) log(LogLevel::FATAL, message, __FILE__, __LINE__, __FUNCTION__)
#endif // LOG_H