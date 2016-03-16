#include "osgdemo.h"
#include <QFileDialog>
#include <osgDB/ReadFile>
#include "Core.h"

OSGDemo::OSGDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_p3DWidget = new Widget3D(this);
	this->setCentralWidget(m_p3DWidget);

	Core::ins()->setRoot(m_p3DWidget->getRoot());
	Core::ins()->setViewer(m_p3DWidget);

	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(slotAddModels()));
}

OSGDemo::~OSGDemo()
{

}

void OSGDemo::slotAddModels()
{
	QStringList listModels = QFileDialog::getOpenFileNames(
		this,
		"Select one or more files to open",
		"D:/SSIT/project/3dEngine/STSDK/Tool/QtDockWidget/Data",
		"Images (*.osg *.ive *.osgd)");

	//m_p3DWidget->getRoot()->removeChildren(0, m_p3DWidget->getRoot()->getNumChildren());
	foreach(QString model, listModels)
	{
		Core::ins()->getRoot()->addChild(osgDB::readNodeFile(model.toLocal8Bit().data()));
	}
}

void OSGDemo::initDockList()
{

}
