#ifndef LOGIMPL_H
#define LOGIMPL_H
#include <string>
enum class LogLevel { _SUCCESS, _INFO, _WARNING, _ERROR, _DEBUG, _FATAL };
void log(LogLevel level, const std::string& message,
         const char* file, int line, const char* function);
#endif // LOGIMPL_H
