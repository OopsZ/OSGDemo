//
// File: Core.h
// Author:lyk
// Date: 2016/03/09
// Desc: 公用静态存储类
//
#ifndef CORE_H
#define CORE_H

#include <osgViewer/Viewer>
#include <osg/Group>

class Core
{
public:
	static Core* ins();
	static void destory();

	osg::Group* getRoot();
	osg::Group* getCordonNode();
	osgViewer::Viewer* getViewer();

	void setViewer(osgViewer::Viewer* viewer);
	void setRoot(osg::Group* root);

private:
	Core();
	~Core();

private:
	static Core* m_pIns;
	osg::ref_ptr<osgViewer::Viewer> m_pViewer;
	osg::ref_ptr<osg::Group> m_pRoot;		// 根节点
	osg::ref_ptr<osg::Group> m_pCordonNode;	// 警戒线节点
};

#endif // CORE_H
