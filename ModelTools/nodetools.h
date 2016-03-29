//
// File: nodetools.h
// Author:lyk
// Date: 2016/02/16
// Desc: 关于节点操作的集合,均为static
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

	// 节点及其子节点透明
	static void setAlpha(osg::StateSet* ss, float alpha = 0.5,
		osg::StateAttribute::GLModeValue value = osg::StateAttribute::ON
		| osg::StateAttribute::OVERRIDE);

	// 清除透明
	static void clearAlpha(osg::StateSet* ss);

private:
	
};

#endif // NODETOOLS_H
