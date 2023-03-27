#ifndef LOGSTREAM_H
#define LOGSTREAM_H
#include "logimpl.h"
#include <sstream>
using namespace std;

class LogStream {
public:
    LogStream(LogLevel level, const char* file, int line, const char* function)
        : m_level(level), m_file(file), m_line(line), m_function(function)
    {}

    template <typename T>
    LogStream& operator<<(const T& value) {
        m_ss << value;
        return *this;
    }

    ~LogStream() {
        log(m_level, m_ss.str(), m_file, m_line, m_function);
    }

private:
    std::stringstream m_ss;
    LogLevel m_level;
    const char* m_file;
    int m_line;
    const char* m_function;
};
#endif // LOGSTREAM_H
