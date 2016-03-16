//
// File: Export.h
// Author:lyk
// Date: 2016/03/16
// Desc: µ¼³ö
//
#ifndef MODELTOOLS_EXPORTS_H
#define MODELTOOLS_EXPORTS_H

#ifndef MODELTOOLS_EXPORTS
#define MODELTOOLS_EXPORT __declspec(dllimport)
#else
#define MODELTOOLS_EXPORT __declspec(dllexport)
#endif

#endif // MODELTOOLS_EXPORTS_H
