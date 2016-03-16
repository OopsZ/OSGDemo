//
// File: Export.h
// Author:lyk
// Date: 2016/03/16
// Desc: µ¼³ö
//
#ifndef EXPORT_COMMON_H
#define EXPORT_COMMON_H

#ifndef COMMON_EXPORTS
#define COMMON_EXPORT __declspec(dllimport)
#else
#define COMMON_EXPORT __declspec(dllexport)
#endif

#endif // EXPORT_COMMON_H
