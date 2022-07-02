#ifndef AC_LOG_H
#define AC_LOG_H

#pragma once

#include <iosfwd>
#include <ostream>
#include <utility>

namespace ashen
{
namespace ac
{

struct Logger
{
    static void Init(const wchar_t* path);
    static std::wostream& Get();


    template<typename OStream, typename T, typename... U>
    static void Log(OStream& os, T&& first, U&&... args)
    {
        os << first;
        if constexpr (sizeof...(args) == 0) {
            os << std::endl;
        } else {
            os << ' ';
            Log(os, args...);
        }
    }
};



} // namespace ac
} // namespace ashen

#ifdef AC_LOGGING_ENABLED
#define AC_LOG(...) ashen::ac::Logger::Log(ashen::ac::Logger::Get(), __VA_ARGS__)
#else
#define AC_LOG(...) (void)0
#endif


#endif // AC_LOG_H
