#ifndef AC_MATCHER_H
#define AC_MATCHER_H

#pragma once

#include <Windows.h>
#include <OAIdl.h>
#include <config.h>

#ifdef __cplusplus
extern "C" {
#endif


AC_MATCHER_API void WINAPI AcMatcher_Init(BSTR logPath);

// patterns - an array of BSTR
AC_MATCHER_API void* WINAPI AcMatcher_Create(BSTR* patterns, int size);

AC_MATCHER_API int WINAPI AcMatcher_Match(void* obj, BSTR str);

AC_MATCHER_API int WINAPI AcMatcher_MatchLongestL(void* obj, BSTR str);

AC_MATCHER_API void  WINAPI AcMatcher_Free(void* obj);

#ifdef __cplusplus
}
#endif

#endif // AC_MATCHER_H 