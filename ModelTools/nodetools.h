//
// File: nodetools.h
// Author:lyk
// Date: 2016/02/16
// Desc:
//
#ifndef NODETOOLS_H
#define NODETOOLS_H

#include <osg/Node>
#include "Export.h"

class MODELTOOLS_EXPORT NodeTools
{
public:
	NodeTools();
	~NodeTools();

	// 高亮
	static void setHighLightOn(osg::Node* node,
		osg::Vec4& color = osg::Vec4(1, 0, 0, 1));

	// 取消高亮
	static void setHighLightOff(osg::Node* node);

private:
	
};

#endif // NODETOOLS_H
