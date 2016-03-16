#ifndef EVENTADAPTER_H
#define EVENTADAPTER_H
#include <QtOpenGL/QGLWidget>
#include <osgViewer/View>
#include <QtGui/QKeyEvent>
#include "Export.h"

class WIDGET3D_EXPORT EventAdapter : public QGLWidget
{
	Q_OBJECT
public:
	EventAdapter(QWidget* parent=0);
	~EventAdapter(void);

	osgViewer::GraphicsWindow* getGraphicsWindow(){ return m_pGraphicsWindow.get(); }
	const osgViewer::GraphicsWindow* getGraphicsWindow()const{ return m_pGraphicsWindow.get(); }

protected:
	// Qt与OSG的事件传递;
	virtual void resizeGL(int width,int height);
	virtual void keyPressEvent(QKeyEvent* event);
	virtual void keyReleaseEvent(QKeyEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseDoubleClickEvent(QMouseEvent *);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void wheelEvent(QWheelEvent*);

protected:
	osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> m_pGraphicsWindow;

private: 
	void setKeyboardModifiers(QInputEvent* event);
};

#endif // EVENTADAPTER_H
