#ifndef OSGDEMO_H
#define OSGDEMO_H

#include <QMainWindow>
#include "ui_osgdemo.h"
#include "widget3d.h"
#include "CordonTool.h"
#include "SceneTreeWidget.h"

class OSGDemo : public QMainWindow
{
	Q_OBJECT

public:
	OSGDemo(QWidget *parent = 0);
	~OSGDemo();

private slots:
	void slotAddModels();
	void slotCordon();

private:
	void initDockList();

private:
	Ui::OSGDemoClass ui;
	Widget3D* m_p3DWidget;
	SceneTreeWidget* m_pSceneTree;
	osg::ref_ptr<CordonTool> m_pCordon;
};

#endif // OSGDEMO_H
