#ifndef LOGSTREAM_H
#define LOGSTREAM_H
#include "logimpl.h"
#include <sstream>
using namespace std;

class LogStream {
public:
    LogStream(LogLevel level, const char* file, int line, const char* function);

    template <typename T>
    LogStream& operator<<(const T& value) {
        m_ss << value;
        return *this;
    }

    ~LogStream();

private:
    std::stringstream m_ss;
    LogLevel m_level;
    const char* m_file;
    int m_line;
    const char* m_function;
};
#endif // LOGSTREAM_H
