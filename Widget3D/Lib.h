//
// File: Lib.h
// Author:lyk
// Date: 2016/03/09
// Desc: “¿¿µæ≤Ã¨ø‚
//
#ifndef WIDGET_LIB_H
#define WIDGET_LIB_H

#ifdef _DEBUG
#pragma comment(lib, "OpenThreadsd.lib")
#pragma comment(lib, "osgd.lib")
#pragma comment(lib, "osgViewerd.lib")
#pragma comment(lib, "osgGAd.lib")
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgUtild.lib")
#else
#pragma comment(lib, "OpenThreads.lib")
#pragma comment(lib, "osg.lib")
#pragma comment(lib, "osgViewer.lib")
#pragma comment(lib, "osgGA.lib")
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgUtil.lib")
#endif
#endif // WIDGET_LIB_H