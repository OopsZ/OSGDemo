//
// File: PickModel.h
// Author:lyk
// Date: 2016/01/26
// Desc: ֻ���ڶ�ģ�͵�pick����������һ������
//
#ifndef PICKMODEL_H
#define PICKMODEL_H
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIEventHandler>
#include "Export.h"

class PICKTOOLS_EXPORT PickModel : public osgGA::GUIEventHandler
{
public:
	PickModel();
	~PickModel();

	bool enable() { return m_bEnable; }
	void enable(bool bEnable) { m_bEnable = bEnable; }

	PickModel(const PickModel& eh,const osg::CopyOp& copyop) {}

protected:
	virtual bool handle(const osgGA::GUIEventAdapter& ea,
		osgGA::GUIActionAdapter& aa);
	virtual void moveEvent() {}
	virtual void doubleClicked() {}
	virtual void releaseEvent() {}
	virtual void frame() {}
	virtual void mouseRightClicked() {}
	virtual void mouseLeftClicked(osg::Vec3& pos) {}

private:
	bool pickPos(const osgGA::GUIEventAdapter& ea,
		osgGA::GUIActionAdapter& aa, osg::Vec3& pos);

protected:
	osg::NodePath m_nodePath;
	bool m_bEnable;

private:
	osg::Vec3 m_vecLastPos;      // ��¼PUSH״̬��λ�ã���release���жԱ�
};

#endif // PICKMODEL_H
