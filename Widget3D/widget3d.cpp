#include "widget3d.h"
#include <osgGA/TrackballManipulator>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/ReadFile>
#include "Lib.h"

Widget3D::Widget3D(QWidget *parent)
	: EventAdapter(parent)
{
	this->setMouseTracking(true);
	initViewer();
}

Widget3D::~Widget3D()
{

}

void Widget3D::initViewer()
{
	m_pRoot = new osg::Group;
	m_pRoot->setName("Root");

	this->setCamera(createCamera(0, 0, width(), height()));
	osg::ref_ptr<osgGA::TrackballManipulator> pManipulator =
		new osgGA::TrackballManipulator;
	this->setCameraManipulator(pManipulator);
	this->addEventHandler(new osgViewer::StatsHandler);
	this->addEventHandler(new osgViewer::ThreadingHandler());
	this->addEventHandler(new osgViewer::HelpHandler);
	this->addEventHandler(new osgGA::StateSetManipulator(this->getCamera()->getOrCreateStateSet()));
	this->setThreadingModel(osgViewer::Viewer::SingleThreaded);

	m_pRoot->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);
	m_pRoot->getOrCreateStateSet()->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);
	this->setSceneData(m_pRoot);

	 startTimer(0);
}

osg::ref_ptr<osg::Camera> Widget3D::createCamera( int x, int y, int w, int h )
{
	m_pGraphicsWindow = new osgViewer::GraphicsWindowEmbedded(x, y, w, h);
	osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	traits->windowDecoration = true;
	traits->x = x;
	traits->y = y;
	traits->width = w;
	traits->height = h;
	traits->doubleBuffer = true;
	traits->sharedContext = 0;

	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	camera->setGraphicsContext(m_pGraphicsWindow);
	camera->setClearColor(osg::Vec4(0.3, 0.3, 0.6, 0.8));
	camera->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));
	camera->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	camera->setProjectionMatrixAsPerspective(
		30.0f, static_cast<double>(traits->width) / static_cast<double>(traits->height), 1.0f, 10000.0f);

	return camera.release();
}

void Widget3D::paintGL()
{
	frame();
}
