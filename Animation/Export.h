//
// File: Export.h
// Author:lyk
// Date: 2016/03/16
// Desc: µ¼³ö
//
#ifndef ANIMATION_EXPORTS_H
#define ANIMATION_EXPORTS_H

#ifndef ANIMATION_EXPORTS
#define ANIMATION_EXPORT __declspec(dllimport)
#else
#define ANIMATION_EXPORT __declspec(dllexport)
#endif

#endif // ANIMATION_EXPORTS_H
