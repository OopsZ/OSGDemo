#include "osgdemo.h"
#include <QFileDialog>
#include <QFileInfo>
#include <osgDB/ReadFile>
#include "Core.h"
#include "EagleEyeManipulator.h"
#include "DirectionTool.h"
#include "SceneTreeItem.h"

OSGDemo::OSGDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_pCordon = NULL;
	m_p3DWidget = new Widget3D(this);
	this->setCentralWidget(m_p3DWidget);

	Core::ins()->setRoot(m_p3DWidget->getRoot());
	Core::ins()->setViewer(m_p3DWidget);

	osg::Vec3d eye = osg::Vec3d(3.50452,-80.6569,18.3717);
	osg::Vec3d center = osg::Vec3d(-1.0,-40.0,2.0);
	osg::Vec3d up = DirectionTool::getUpDir(center - eye);

	EagleEyeManipulator* manipu = new EagleEyeManipulator;
	manipu->setHomePosition(eye, center, up);
	manipu->home(0);
	manipu->setCenter(osg::Vec3(-1.0,-40.0,2.0));
	m_p3DWidget->setCameraManipulator(manipu);

	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(slotAddModels()));
	connect(ui.actionCordon, SIGNAL(triggered()), this, SLOT(slotCordon()));
}

OSGDemo::~OSGDemo()
{

}

void OSGDemo::slotAddModels()
{
	QStringList listModels = QFileDialog::getOpenFileNames(
		this,
		"Select one or more files to open",
		"D:/SSIT/project/3dEngine/ZheJiangDianXin/Win32/Data/SceneData",
		"Images (*.osg *.ive *.osgd)");

	m_p3DWidget->getRoot()->removeChildren(0, m_p3DWidget->getRoot()->getNumChildren());
	ui.treeWidget->clear();
	ui.treeWidget->setColumnCount(1);
	ui.treeWidget->setHeaderHidden(true);
	foreach(QString model, listModels)
	{
		osg::Node* pNode = osgDB::readNodeFile(model.toLocal8Bit().data());
		Core::ins()->getRoot()->addChild(pNode);

		// Ìí¼Ó³¡¾°
		QFileInfo info(model);
		SceneTreeItem* pItem = new SceneTreeItem;
		pItem->setText(0, info.fileName());
		pItem->setNode(pNode);
		ui.treeWidget->addTopLevelItem(pItem);
	}
}

void OSGDemo::initDockList()
{

}

void OSGDemo::slotCordon()
{
	if (NULL == m_pCordon)
	{
		m_pCordon = new CordonTool;
		Core::ins()->getViewer()->addEventHandler(m_pCordon);
	}

	m_pCordon->beginCordon();
}
