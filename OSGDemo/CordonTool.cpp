#include "CordonTool.h"
#include "FileUtils.h"
#include "Core.h"
#include <QUuid>

CordonTool::CordonTool(QObject* parent)
: QObject(parent)
{
	
}

CordonTool::~CordonTool()
{
	
}

void CordonTool::mouseLeftClicked( osg::Vec3& pos )
{
	if (m_pCordon && m_bEnable)
	{
		m_pCordon->addCardon(pos);
	}
}

void CordonTool::doubleClicked()
{
	emit signalFinishedCordon();
}

void CordonTool::beginCordon()
{
	m_pCordon = new Cordon;
	std::string name = "Cordon:";
	name.append(QUuid::createUuid().toString().toStdString());
	m_pCordon->setName(name);
	m_pCordon->setCordonResource(FileUtils::ins()->getPath("jingjiexian.jpg"),
		FileUtils::ins()->getPath("Dunzi.IVE"));
	Core::ins()->getCordonNode()->addChild(m_pCordon);
	m_bEnable = true;
}

void CordonTool::endCordon()
{
	m_bEnable = false;
}
