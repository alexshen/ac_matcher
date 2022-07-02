cmake_minimum_required (VERSION 3.10)

project(ac_matcher)

set(AC_BUILD_TYPE STATIC)
add_subdirectory(ac)

set(TARGET_NAME ac_matcher)
add_library (${TARGET_NAME} SHARED
	ac_log.cpp
	ac_log.h
	ac_matcher.cpp 
	ac_matcher.h
	config.h
)

target_include_directories(${TARGET_NAME} PRIVATE ${PROJECT_SOURCE_DIR} ac)
target_compile_definitions(${TARGET_NAME} PRIVATE AC_MATCHER_BUILDING_DLL)

option(AC_LOGGING_ENABLED "Enable logging" FALSE)
if (AC_LOGGING_ENABLED)
	target_compile_definitions(${TARGET_NAME} PRIVATE AC_LOGGING_ENABLED)
endif()

target_compile_features(${TARGET_NAME} PRIVATE "cxx_std_17")

set(AC_MATCHER_PUBLIC_HEADERS ac_matcher.h)
set_target_properties(${TARGET_NAME} PROPERTIES PUBLIC_HEADER "${AC_MATCHER_PUBLIC_HEADERS}")

target_link_libraries(${TARGET_NAME} PRIVATE ac)
install(TARGETS ${TARGET_NAME} PUBLIC_HEADER)
