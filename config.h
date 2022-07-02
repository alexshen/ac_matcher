#ifndef AC_MATCHER_CONFIG_H
#define AC_MATCHER_CONFIG_H

#pragma once

#define AC_MATCHER_IMPORT __declspec(dllimport)
#define AC_MATCHER_EXPORT __declspec(dllexport)

#ifndef AC_MATCHER_DEF_FILE
#ifdef AC_MATCHER_BUILDING_DLL
#  define AC_MATCHER_API AC_MATCHER_EXPORT
#else
#  define AC_MATCHER_API AC_MATCHER_IMPORT
#endif
#else
#  define AC_MATCHER_API
#endif

#endif // AC_MATCHER_CONFIG_H
