//
// File: ModelBase.h
// Author:lyk
// Date: 2016/03/22
// Desc: ģ�͵Ļ�������
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
	bool m_bIsHightLight;             // �Ƿ����
	osg::Vec4 m_vecLightColor;        // ������ɫ
};

#endif // MODELBASE_H
