//
// File: EagleEyeManipulator.h
// Author:lyk
// Date: 2016/03/18
// Desc: 鹰眼漫游操作器
//
#ifndef EAGLEEYEMANIPULATOR_H
#define EAGLEEYEMANIPULATOR_H

#include "Export.h"
#include <osgGA/StandardManipulator>

class MANIPULOTOR_EXPORT EagleEyeManipulator : public osgGA::StandardManipulator
{
public:
	EagleEyeManipulator();
	~EagleEyeManipulator();

	void setCenter(const osg::Vec3 & center);
	// Matrix
	virtual void setByMatrix(const osg::Matrixd& matrix);
	virtual void setByInverseMatrix(const osg::Matrixd& matrix);

	virtual osg::Matrixd getMatrix() const;
	virtual osg::Matrixd getInverseMatrix() const;

	// Home
	virtual void setHomePosition(const osg::Vec3d& eye,
		const osg::Vec3d& center, const osg::Vec3d& up,
		bool autoComputeHomePosition =false );
	virtual void computeHomePosition(const osg::Camera *camera,
		bool useBoundingBox);
	virtual void home(double currenttime);
	virtual void home(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

	// Handle
	virtual bool handleFrame(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);
	virtual bool handleResize(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);
	virtual bool handleMouseMove(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);
	virtual bool handleMouseDrag(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);
	virtual bool handleMousePush(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);
	virtual bool handleMouseRelease(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);
	virtual bool handleMouseWheel(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

	// Mouse Event
	virtual bool performMovementLeftMouseButton(const double eventTimeDelta, const double dx, const double dy);
	virtual bool performMovementRightMouseButton(const double eventTimeDelta, const double dx, const double dy);

	virtual void setTransformation(const osg::Vec3d&, const osg::Quat&) {}
	virtual void setTransformation(const osg::Vec3d& eye, const osg::Vec3d& center, const osg::Vec3d& up);
	virtual void getTransformation(osg::Vec3d&, osg::Quat&) const {}
	virtual void getTransformation(osg::Vec3d&, osg::Vec3d&, osg::Vec3d&) const {}

private:
	void updateViewport();

private:
	// home位置
	osg::Vec3 m_homeEye;
	osg::Vec3 m_homeCenter;
	osg::Vec3 m_homeUp;
	osg::Vec3 m_leftDirection;
	osg::Vec3 m_frowardDirection;

	// 视点
	osg::Vec3 m_eye;
	osg::Vec3 m_center;
	osg::Vec3 m_up;

	// 
	float m_fLookDistance;
	float m_fLookMinDistance;
	float m_fLookMaxDistnace;

	float m_fLookDownAngle;
	float m_fLookDownMinAngle;
	float m_fLookDownMaxAngle;

	float m_fLeftAngle;
};

#endif // EAGLEEYEMANIPULATOR_H
