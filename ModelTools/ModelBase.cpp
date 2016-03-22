#include "ModelBase.h"
#include "NodeTools.h"
#include <osgDB/ReadFile>

ModelBase::ModelBase()
{
	m_bIsHightLight = false;
	m_vecLightColor = osg::Vec4(1.0, 0.0, 0.0, 1.0);
}

ModelBase::~ModelBase()
{

}

void ModelBase::create(const std::string& path, const std::string& name)
{
	if (path == "")
	{
		return;
	}

	osg::ref_ptr<osg::Node> pNode = osgDB::readNodeFile(path);
	if (pNode)
	{
		pNode->setName(name);
		addChild(pNode);
	}
}

void ModelBase::setHightLight(bool on)
{
	if (on)
	{
		if (m_bIsHightLight)
		{
			return;
		}
		m_bIsHightLight = true;
		NodeTools::setHighLightOn(this, m_vecLightColor);
	}
	else
	{
		m_bIsHightLight = false;
		NodeTools::setHighLightOff(this);
	}
}

void ModelBase::setHightLightColor(const osg::Vec4& color)
{
	m_vecLightColor = color;
}
