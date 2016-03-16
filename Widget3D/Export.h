//
// File: Export.h
// Author:lyk
// Date: 2016/03/16
// Desc: µ¼³ö
//
#ifndef EXPORT_WIDGET3D_H
#define EXPORT_WIDGET3D_H

#ifndef WIDGET3D_LIB
#define WIDGET3D_EXPORT __declspec(dllimport)
#else
#define WIDGET3D_EXPORT __declspec(dllexport)
#endif

#endif // EXPORT_WIDGET3D_H
