//
// File: Lib.h
// Author:lyk
// Date: 2016/03/16
// Desc: “¿¿µæ≤Ã¨ø‚
//
#ifndef MODELTOOLS_LIB_H
#define MODELTOOLS_LIB_H

#ifdef _DEBUG
#pragma comment(lib, "osgd.lib")
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgGAd.lib")
#pragma comment(lib, "osgViewerd.lib")
#else
#pragma comment(lib, "osg.lib")
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgGA.lib")
#pragma comment(lib, "osgViewer.lib")
#endif

#endif // MODELTOOLS_LIB_H
