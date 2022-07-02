#include <ac_matcher.h>
#include <vector>
#include <cassert>
#include <ac.h>
#include <ac_log.h>
#include <iomanip>

void WINAPI AcMatcher_Init(BSTR logPath)
{
    assert(logPath);
    ashen::ac::Logger::Init(logPath);
}

void* WINAPI AcMatcher_Create(BSTR* patterns, int size)
{
    assert(patterns && size >= 0);
    std::vector<unsigned int> lens;
    lens.reserve(size);

    for (int i = 0; i < size; ++i) {
        // get the byte length since patterns are treated as bytes
        lens.push_back(SysStringByteLen(patterns[i]));
        AC_LOG(std::hex, static_cast<void*>(patterns[i]), ": ", patterns[i], ", ", SysStringByteLen(patterns[i]));
    }

    auto ac = ac_create(reinterpret_cast<const char**>(reinterpret_cast<std::uintptr_t>(patterns)),
                     lens.data(),
                     static_cast<unsigned int>(size));
    return ac;
}

int WINAPI AcMatcher_Match(void* obj, BSTR str)
{
    assert(obj && str);

    auto result = ac_match(static_cast<ac_t*>(obj), 
                           reinterpret_cast<const char*>(str), 
                           SysStringByteLen(str));
    return result.match_begin >= 0 ? result.pattern_idx : -1;
}

int WINAPI AcMatcher_MatchLongestL(void* obj, BSTR str)
{
    assert(obj && str);
    auto result = ac_match_longest_l(static_cast<ac_t*>(obj), 
                                     reinterpret_cast<const char*>(str), 
                                     SysStringByteLen(str));
    return result.match_begin >= 0 ? result.pattern_idx : -1;
}

void  WINAPI AcMatcher_Free(void* obj)
{
    assert(obj);
    ac_free(static_cast<ac_t*>(obj));
}
