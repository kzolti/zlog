#ifndef LOGIMPL_H
#define LOGIMPL_H
#include <string>
enum class LogLevel { SUCCESS, INFO, WARNING, ERROR, DEBUG, FATAL };
void log(LogLevel level, const std::string& message,
         const char* file, int line, const char* function);
#endif // LOGIMPL_H
