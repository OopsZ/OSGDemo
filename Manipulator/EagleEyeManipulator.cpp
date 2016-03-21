#include "EagleEyeManipulator.h"
#include "Lib.h"
#include "DirectionTool.h"

EagleEyeManipulator::EagleEyeManipulator()
{
	m_homeEye = osg::Vec3(0, 0, 0);
	m_homeCenter = osg::Vec3(0, 0, 0);
	m_homeUp = osg::Vec3(0, 0, 0);

	m_eye = osg::Vec3(0, 0, 0);
	m_center = osg::Vec3(0, 0, 0);
	m_up = osg::Vec3(0, 0, 0);

	m_leftDirection = -osg::X_AXIS;
	m_frowardDirection = osg::Y_AXIS;

	m_fLookDistance = 10.0f;
	m_fLookMinDistance = 2.0f;
	m_fLookMaxDistnace = 100.0f;

	m_fLookDownAngle = osg::PI_2 * 0.5;
	m_fLookDownMinAngle = osg::PI_2 * 0.05;
	m_fLookDownMaxAngle = osg::PI_2 * 0.95;

	m_fLeftAngle = 0.0f;
}

EagleEyeManipulator::~EagleEyeManipulator()
{

}

void EagleEyeManipulator::setCenter(const osg::Vec3 & center)
{
	osg::Vec3 up = DirectionTool::getUpDir(center - m_eye);

	setTransformation(m_eye, center, up);
}

void EagleEyeManipulator::setByMatrix(const osg::Matrixd& matrix)
{
	setByInverseMatrix(osg::Matrix::inverse(matrix));
}

void EagleEyeManipulator::setByInverseMatrix(const osg::Matrixd& matrix)
{
	osg::Vec3 eye, center, up;
	matrix.getLookAt(eye, center, up);

	setTransformation(eye, center, up);
}

osg::Matrixd EagleEyeManipulator::getMatrix() const
{
	return osg::Matrix::inverse(osg::Matrix::lookAt(m_eye, m_center, m_up));
}

osg::Matrixd EagleEyeManipulator::getInverseMatrix() const
{
	return osg::Matrix::lookAt(m_eye, m_center, m_up);
}

void EagleEyeManipulator::setHomePosition(const osg::Vec3d& eye,
										  const osg::Vec3d& center,
										  const osg::Vec3d& up,
										  bool autoComputeHomePosition /*=false */)
{
	setAutoComputeHomePosition(autoComputeHomePosition);
	m_homeEye = eye;
	m_homeCenter = center;
	m_homeUp = up;
}

void EagleEyeManipulator::computeHomePosition(const osg::Camera *camera,
											  bool useBoundingBox)
{
	
}

void EagleEyeManipulator::home(double currenttime)
{
	if (getAutoComputeHomePosition())
	{
		computeHomePosition(NULL, false);
	}

	setTransformation(m_homeEye, m_homeCenter, m_homeUp);

	flushMouseEventStack();
}

void EagleEyeManipulator::home(const osgGA::GUIEventAdapter& ea,
							   osgGA::GUIActionAdapter& us)
{
	if (getAutoComputeHomePosition())
	{
		computeHomePosition(NULL, false);
	}

	setTransformation(m_homeEye, m_homeCenter, m_homeUp);
	us.requestRedraw();
	us.requestContinuousUpdate(false);

	flushMouseEventStack();
}

bool EagleEyeManipulator::handleFrame(const osgGA::GUIEventAdapter& ea,
									  osgGA::GUIActionAdapter& us)
{
	updateViewport();
	return osgGA::StandardManipulator::handleFrame(ea, us);
}

bool EagleEyeManipulator::handleResize(const osgGA::GUIEventAdapter& ea,
									   osgGA::GUIActionAdapter& us)
{
	init(ea, us);
	us.requestRedraw();

	return true;
}

bool EagleEyeManipulator::handleMouseMove(const osgGA::GUIEventAdapter& ea,
										  osgGA::GUIActionAdapter& us)
{
	return false;
}

bool EagleEyeManipulator::handleMouseDrag(const osgGA::GUIEventAdapter& ea,
										  osgGA::GUIActionAdapter& us)
{
	addMouseEvent(ea);

	if (performMovement())
	{
		us.requestRedraw();
	}

	us.requestContinuousUpdate(false);
	return true;
}

bool EagleEyeManipulator::handleMousePush(const osgGA::GUIEventAdapter& ea,
										  osgGA::GUIActionAdapter& us)
{
	flushMouseEventStack();
	addMouseEvent(ea);
	if (performMovement())
	{
		us.requestRedraw();
	}
	us.requestContinuousUpdate(false);
	return true;
}

bool EagleEyeManipulator::handleMouseRelease(const osgGA::GUIEventAdapter& ea,
										   osgGA::GUIActionAdapter& us)
{
	if (ea.getButtonMask() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
	{
		double timeDelt = _ga_t0.valid() ? (ea.getTime() - _ga_t0->getTime()) : DBL_MAX;
		if (timeDelt > 0.02)
		{
			flushMouseEventStack();
		}
	
		if (isMouseMoving())
		{
			if (performMovement())
			{
				us.requestRedraw();
				us.requestContinuousUpdate(true);
			}

			return true;
		}
	}

	flushMouseEventStack();
	addMouseEvent(ea);
	if (performMovement())
	{
		us.requestRedraw();
	}
	us.requestContinuousUpdate(false);
	return true;
}

bool EagleEyeManipulator::handleMouseWheel(const osgGA::GUIEventAdapter& ea,
										   osgGA::GUIActionAdapter& us)
{
	// ÖÐ¼üup£¬down
	switch (ea.getScrollingMotion())
	{
	case osgGA::GUIEventAdapter::SCROLL_UP:
		{
			float distance = m_fLookDistance * (1 - 0.1);
			if (distance >= m_fLookMinDistance && distance <= m_fLookMaxDistnace)
			{
				m_fLookDistance = distance;
			}
			us.requestRedraw();
			return true;
		}
	case osgGA::GUIEventAdapter::SCROLL_DOWN:
		{
			float distance = m_fLookDistance * (1 + 0.1);
			if (distance >= m_fLookMinDistance && distance <= m_fLookMaxDistnace)
			{
				m_fLookDistance = distance;
			}
			us.requestRedraw();
			return true;
		}
	default:
		return false;
	}

	return false;
}

bool EagleEyeManipulator::performMovementLeftMouseButton(const double eventTimeDelta,
														 const double dx, const double dy)
{
	m_center -= m_frowardDirection * m_fLookDistance * dy / 4;
	m_center += m_leftDirection * m_fLookDistance * dx / 3;

	return false;
}

bool EagleEyeManipulator::performMovementRightMouseButton(const double eventTimeDelta,
														  const double dx, const double dy)
{
	m_fLookDownAngle -= osg::PI_4 * dy / 2;
	m_fLeftAngle += osg::PI_2 * dx / 2;
	m_fLookDownAngle = m_fLookDownAngle > m_fLookDownMaxAngle ? m_fLookDownMaxAngle : m_fLookDownAngle;
	m_fLookDownAngle = m_fLookDownAngle < m_fLookDownMinAngle ? m_fLookDownMinAngle : m_fLookDownAngle;

	return false;
}

void EagleEyeManipulator::setTransformation(const osg::Vec3d& eye,
											const osg::Vec3d& center,
											const osg::Vec3d& up)
{
	osg::Vec3 lookDir = center - eye;
	lookDir.normalize();

	double cos = lookDir * -osg::Z_AXIS / lookDir.length() / (-osg::Z_AXIS).length();
	m_fLookDownAngle = acos(cos);
	m_fLookDownAngle = m_fLookDownAngle > m_fLookDownMaxAngle ? m_fLookDownMaxAngle : m_fLookDownAngle;
	m_fLookDownAngle = m_fLookDownAngle < m_fLookDownMinAngle ? m_fLookDownMinAngle : m_fLookDownAngle;

	float distance = (eye - center).length();
	distance = distance > m_fLookMaxDistnace ? m_fLookMaxDistnace : distance;
	distance = distance < m_fLookMinDistance ? m_fLookMinDistance : distance;
	m_fLookDistance = distance;

	osg::Vec3 diry = osg::Vec3(lookDir.x(), lookDir.y(), 0);
	osg::Vec3 diryRef = osg::Y_AXIS;
	if ((diryRef ^ diry).z() > 0)
	{
		m_fLeftAngle = DirectionTool::getCosRadian(diry, diryRef);
	}
	else
	{
		m_fLeftAngle = -DirectionTool::getCosRadian(diry, diryRef);
	}

	m_center = eye + lookDir * m_fLookDistance;
	updateViewport();
}

void EagleEyeManipulator::updateViewport()
{
	float hDist = m_fLookDistance * sin(m_fLookDownAngle);
	float vDist = m_fLookDistance * cos(m_fLookDownAngle);

	osg::Vec3 lookdirNorot= osg::Vec3(0, hDist, -vDist);
	osg::Vec3 lookdirRot = lookdirNorot * osg::Matrix::rotate(m_fLeftAngle, osg::Z_AXIS);

	m_eye = m_center - lookdirRot;

	m_up = DirectionTool::getUpDir(m_center - m_eye);
}
