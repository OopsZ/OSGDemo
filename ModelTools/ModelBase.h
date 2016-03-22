//
// File: ModelBase.h
// Author:lyk
// Date: 2016/03/22
// Desc: 模型的基处理类
//
#ifndef MODELBASE_H
#define MODELBASE_H

#include "Export.h"
#include <osg/MatrixTransform>

class MODELTOOLS_EXPORT ModelBase : public osg::MatrixTransform
{
public:
	ModelBase();
	~ModelBase();

	virtual void create(osg::Node* node){}
	virtual void create(const std::string& path, const std::string& name);

	void setHightLight(bool on);
	bool getHightLight() { return m_bIsHightLight; }
	void setHightLightColor(const osg::Vec4& color);
	osg::Vec4& getHightLightColor() { return m_vecLightColor; }

private:
	bool m_bIsHightLight;             // 是否高亮
	osg::Vec4 m_vecLightColor;        // 高亮颜色
};

#endif // MODELBASE_H
