//
// File: Export.h
// Author:lyk
// Date: 2016/03/16
// Desc: µ¼³ö
//
#ifndef PICKTOOLS_EXPORTS_H
#define PICKTOOLS_EXPORTS_H

#ifndef PICKTOOLS_EXPORTS
#define PICKTOOLS_EXPORT __declspec(dllimport)
#else
#define PICKTOOLS_EXPORT __declspec(dllexport)
#endif

#endif // PICKTOOLS_EXPORTS_H
