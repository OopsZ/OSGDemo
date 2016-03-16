#ifndef WIDGET3D_H
#define WIDGET3D_H

#include <QGLWidget>
#include <QMoveEvent>
#include <osgViewer/Viewer>
#include <osg/Group>
#include "EventAdapter.h"
#include "Export.h"

class WIDGET3D_EXPORT Widget3D : public EventAdapter, public osgViewer::Viewer
{
	Q_OBJECT

public:
	Widget3D(QWidget *parent = 0);
	~Widget3D();

	osg::ref_ptr<osg::Group> getRoot(){ return m_pRoot; }

protected:
	virtual void paintGL();
	virtual void timerEvent(QTimerEvent *event){ update(); }

private:
	void initViewer();
	osg::ref_ptr<osg::Camera> createCamera(int x, int y, int w, int h);

private:
	osg::ref_ptr<osg::Group> m_pRoot;
};

#endif // WIDGET3D_H
