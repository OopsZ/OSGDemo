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
#pragma comment(lib, "osgGAd.lib")
#pragma comment(lib, "osgViewerd.lib")
#pragma comment(lib, "BaseToolsd.lib")
#pragma comment(lib, "Widget3Dd.lib")
#pragma comment(lib, "PickToolsd.lib")
#pragma comment(lib, "ModelToolsd.lib")
#pragma comment(lib, "Manipulatord.lib")
#else
#pragma comment(lib, "osg.lib")
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgGA.lib")
#pragma comment(lib, "osgViewer.lib")
#pragma comment(lib, "BaseTools.lib")
#pragma comment(lib, "Widget3D.lib")
#pragma comment(lib, "PickTools.lib")
#pragma comment(lib, "ModelTools.lib")
#pragma comment(lib, "Manipulator.lib")
#endif

#endif // OSGDEMO_LIB_H
