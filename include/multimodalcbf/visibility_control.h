#ifndef MULTIMODALCBF__VISIBILITY_CONTROL_H_
#define MULTIMODALCBF__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MULTIMODALCBF_EXPORT __attribute__ ((dllexport))
    #define MULTIMODALCBF_IMPORT __attribute__ ((dllimport))
  #else
    #define MULTIMODALCBF_EXPORT __declspec(dllexport)
    #define MULTIMODALCBF_IMPORT __declspec(dllimport)
  #endif
  #ifdef MULTIMODALCBF_BUILDING_LIBRARY
    #define MULTIMODALCBF_PUBLIC MULTIMODALCBF_EXPORT
  #else
    #define MULTIMODALCBF_PUBLIC MULTIMODALCBF_IMPORT
  #endif
  #define MULTIMODALCBF_PUBLIC_TYPE MULTIMODALCBF_PUBLIC
  #define MULTIMODALCBF_LOCAL
#else
  #define MULTIMODALCBF_EXPORT __attribute__ ((visibility("default")))
  #define MULTIMODALCBF_IMPORT
  #if __GNUC__ >= 4
    #define MULTIMODALCBF_PUBLIC __attribute__ ((visibility("default")))
    #define MULTIMODALCBF_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MULTIMODALCBF_PUBLIC
    #define MULTIMODALCBF_LOCAL
  #endif
  #define MULTIMODALCBF_PUBLIC_TYPE
#endif
#endif  // MULTIMODALCBF__VISIBILITY_CONTROL_H_
// Generated 24-Mar-2026 11:54:34
// Copyright 2019-2020 The MathWorks, Inc.
