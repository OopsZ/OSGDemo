#include "PickModel.h"
#include <osgViewer/View>
#include <osgUtil/LineSegmentIntersector>
#include "Lib.h"

PickModel::PickModel()
{
	m_bEnable = true;
}

PickModel::~PickModel()
{

}

bool PickModel::handle( const osgGA::GUIEventAdapter& ea,
					   osgGA::GUIActionAdapter& aa )
{
	if (!m_bEnable)
	{
		return false;
	}

	osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
	if (viewer == NULL)
	{
		return false;
	}

	if (ea.getEventType() == osgGA::GUIEventAdapter::FRAME)
	{
		// ֡�����¼�
		frame();
	}
	else if (ea.getEventType() == osgGA::GUIEventAdapter::DOUBLECLICK &&
		ea.getButtonMask() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
	{
		// ˫���¼�
		osgUtil::LineSegmentIntersector::Intersections intersections;
		if (viewer->computeIntersections(ea.getX(), ea.getY(), intersections))
		{
			// ���н��㣬��ֻȡ��һ��
			if (intersections.size() > 0)
			{
				m_nodePath = intersections.begin()->nodePath;
				doubleClicked();
			}
		}
	}
	else if (ea.getEventType() == osgGA::GUIEventAdapter::MOVE)
	{
		// �ƶ��¼�
		osgUtil::LineSegmentIntersector::Intersections intersections;
		if (viewer->computeIntersections(ea.getX(), ea.getY(), intersections))
		{
			// ���н��㣬��ֻȡ��һ��
			if (intersections.size() > 0)
			{
				m_nodePath = intersections.begin()->nodePath;
				moveEvent();
			}
		}
	}
	else if (ea.getEventType() == osgGA::GUIEventAdapter::RELEASE)
	{
		osg::Vec3 pos;
		pickPos(ea, aa, pos);
		if (pos == m_vecLastPos)
		{
			mouseLeftClicked(pos);
		}
		releaseEvent();
	}
	else if (ea.getEventType() == osgGA::GUIEventAdapter::PUSH &&
		ea.getButtonMask() == osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON)
	{
		// �Ҽ������¼�
		mouseRightClicked();
	}
	else if (ea.getEventType() == osgGA::GUIEventAdapter::PUSH &&
		ea.getButtonMask() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
	{
		// ��������¼�
		pickPos(ea, aa, m_vecLastPos);
	}
	
	return false;
}

bool PickModel::pickPos(const osgGA::GUIEventAdapter& ea,
	osgGA::GUIActionAdapter& aa, osg::Vec3& pos)
{
	osgViewer::View* viewer = dynamic_cast<osgViewer::View*>(&aa);
	if (viewer == NULL)
	{
		return false;
	}
	osgUtil::LineSegmentIntersector::Intersections intersections;
	if (viewer->computeIntersections(ea.getX(), ea.getY(), intersections))
	{
		if (intersections.size() > 0)
		{
			pos = intersections.begin()->getWorldIntersectPoint();

			return true;
		}
	}

	return false;
}
