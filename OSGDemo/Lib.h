//
// File: Lib.h
// Author:lyk
// Date: 2016/03/09
// Desc: “¿¿µæ≤Ã¨ø‚
//
#ifndef OSGDEMO_LIB_H
#define OSGDEMO_LIB_H

#ifdef _DEBUG
#pragma comment(lib, "osgd.lib")
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgViewerd.lib")
#pragma comment(lib, "Commond.lib")
#pragma comment(lib, "Widget3Dd.lib")
#else
#pragma comment(lib, "osg.lib")
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgViewer.lib")
#pragma comment(lib, "Common.lib")
#pragma comment(lib, "Widget3D.lib")
#endif
#endif // OSGDEMO_LIB_H