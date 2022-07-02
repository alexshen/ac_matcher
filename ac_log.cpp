#include <ac_log.h>
#include <fstream>
#include <cassert>

namespace
{
    std::wofstream g_log;
}

void ashen::ac::Logger::Init(const wchar_t* path)
{
#if AC_LOGGING_ENABLED
    assert(path && !g_log.is_open());
    g_log.open(path, std::ios::out | std::ios::ate);
#endif
}

std::wostream& ashen::ac::Logger::Get()
{
    return g_log;
}