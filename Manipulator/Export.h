//
// File: Export.h
// Author:lyk
// Date: 2016/03/18
// Desc: µ¼³ö
//
#ifndef MANIPULOTOR_EXPORTS_H
#define MANIPULOTOR_EXPORTS_H

#ifndef MANIPULATOR_EXPORTS
#define MANIPULOTOR_EXPORT __declspec(dllimport)
#else
#define MANIPULOTOR_EXPORT __declspec(dllexport)
#endif

#endif // MANIPULOTOR_EXPORTS_H
