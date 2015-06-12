/**
 * @breif 简单日志
 *      只写最烂的代码.做不可替代那个人
 * @example 
 * @code
 *  // 用法和std::cout一模一样
 *  ylogf(debug,"y_simple_log.log") << "helloworld";
 *  ylogc(base) << "helloworld";
 *  ylogc(debug) << 10 << "的16进制值为:" << std::hex << 10;
 * @endcode
 */

#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>

#define ylogf(level,log_file_path) y::impl::CFileWritter(log_file_path).set_level_to_##level(__FILE__,__FUNCSIG__,__DATE__,__TIME__,__LINE__)
#define ylogc(level) y::impl::CConsoleWritter().set_level_to_##level(__FILE__,__FUNCSIG__,__DATE__,__TIME__,__LINE__)

#define YSIMPLELOG_DEFAULT_LOG_FILE_PATH "y_simple_log.log"
#define YSIMPLELOG_STANDARD_EXP_BEGIN(level) '[' << y::utils::CTime::GetCurrentTimeStr() << "] ["#level"]\t"

#define YSIMPLELOG_BASE_OPERATOR_IMPL(theClass) \
    template<class T>                           \
    theClass& operator <<( const T& val )       \
    {                                           \
        m_stream << val;                        \
        return *this;                           \
    }

#define YSIMPLELOG_IMPL_MEM_FUNC(theClass,level,expBegin,expEnd)    \
    theClass& set_level_to_##level(                                 \
        const char* pSrcFilePath,                                   \
        const char* pSrcFuncSig,                                    \
        const char* pSrcFileComileDate,                             \
        const char* pSrcFileCompileTime,                            \
        const unsigned long int ullSrcFileLine)                     \
    {                                                               \
        m_stream << expBegin;                                       \
        m_endbuf << expEnd;                                         \
        return *this;                                               \
    }

#define YSIMPLELOG_STANDARD_DECLARE(theClass) \
    YSIMPLELOG_BASE_OPERATOR_IMPL(theClass); \
    YSIMPLELOG_IMPL_MEM_FUNC(theClass, debug, YSIMPLELOG_STANDARD_EXP_BEGIN(debug), "\t[" << pSrcFilePath << '@' << std::dec << ullSrcFileLine << " in " << pSrcFuncSig << ']' << '\n'); \
    YSIMPLELOG_IMPL_MEM_FUNC(theClass, base,  YSIMPLELOG_STANDARD_EXP_BEGIN(base), '\n');

namespace y
{
namespace utils
{
class CTime
{
public:
    static std::string GetCurrentTimeStr()
    {
        SYSTEMTIME t;
        ::GetLocalTime(&t);
        char sz[24] = {0};
        sprintf_s(sz, sizeof(sz), "%04d-%02d-%02d %02d:%02d:%02d.%03d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds);
        return sz;
    }
};
}

namespace impl
{
class CFileWritter
{
private:
    std::ofstream     m_stream;
    std::stringstream m_endbuf;

public:
    CFileWritter(const char* pLogFilePath) : m_stream(pLogFilePath ? pLogFilePath : YSIMPLELOG_DEFAULT_LOG_FILE_PATH, std::ios::app) {}
    ~CFileWritter()
    {
        m_stream << m_endbuf.str();
        m_stream.close();
    }
    YSIMPLELOG_STANDARD_DECLARE(CFileWritter);
};

class CConsoleWritter
{
private:
    std::stringstream m_endbuf;
    std::ostream& m_stream;

public:
    CConsoleWritter() : m_stream(std::cout) {}
    ~CConsoleWritter()
    {
        m_stream << m_endbuf.str();
    }

    YSIMPLELOG_STANDARD_DECLARE(CConsoleWritter);
};
}
}
