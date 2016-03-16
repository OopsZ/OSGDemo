//
// File: Export.h
// Author:lyk
// Date: 2016/03/16
// Desc: µ¼³ö
//
#ifndef BASETOOLS_EXPORT_H
#define BASETOOLS_EXPORT_H

#ifndef BASETOOLS_EXPORTS
#define BASETOOLS_EXPORT __declspec(dllimport)
#else
#define BASETOOLS_EXPORT __declspec(dllexport)
#endif

#endif // BASETOOLS_EXPORT_H
