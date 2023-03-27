#include "logstream.h"


LogStream::LogStream(LogLevel level, const char *file, int line, const char *function)
    : m_level(level), m_file(file), m_line(line), m_function(function)
{}

LogStream::~LogStream() {
    log(m_level, m_ss.str(), m_file, m_line, m_function);
}
