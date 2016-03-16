#include "Core.h"

Core* Core::m_pIns = NULL;

Core::Core()
{

}

Core::~Core()
{

}

Core* Core::ins()
{
	if (m_pIns == NULL)
	{
		m_pIns = new Core;
	}

	return m_pIns;
}

void Core::destory()
{
	delete m_pIns;
	m_pIns = NULL;
}

osg::Group* Core::getRoot()
{
	return m_pRoot;
}

osg::Group* Core::getCordonNode()
{
	return m_pCordonNode;
}

osgViewer::Viewer* Core::getViewer()
{
	return m_pViewer;
}

void Core::setViewer(osgViewer::Viewer* viewer)
{
	m_pViewer = viewer;
}

void Core::setRoot(osg::Group* root)
{
	m_pRoot = root;

	m_pCordonNode = new osg::Group;
	m_pCordonNode->setName("Cordon");
	m_pRoot->addChild(m_pCordonNode);
}
