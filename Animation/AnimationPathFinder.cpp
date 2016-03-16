#include "AnimationPathFinder.h"
#include <osg/NodeCallback>
#include "Lib.h"

AnimationPahtVisitor::AnimationPahtVisitor()
{
}

AnimationPahtVisitor::~AnimationPahtVisitor()
{
}

std::vector<osg::ref_ptr<osg::AnimationPath> > AnimationPahtVisitor::getAnimaPath()
{
	return m_vecAnimaPath;
}

std::vector<osg::ref_ptr<osg::AnimationPathCallback> > AnimationPahtVisitor::getAnimaCB()
{
	return m_vecAnimaCB;
}

std::vector<AnimationControl> AnimationPahtVisitor::getAnimaControl()
{
	return m_vecAnimaControl;
}

void AnimationPahtVisitor::apply(osg::Transform& node)
{
	osg::NodeCallback* pNodeCB = dynamic_cast<osg::NodeCallback*>(node.getUpdateCallback());
	while (pNodeCB)
	{
		osg::AnimationPathCallback* animaCB = dynamic_cast<osg::AnimationPathCallback*>(pNodeCB);
		if (animaCB && animaCB->getAnimationPath())
		{
			m_vecAnimaCB.push_back(animaCB);
			m_vecAnimaPath.push_back(animaCB->getAnimationPath());

			AnimationControl anima;
			anima.m_pNode = &node;
			anima.m_pAnimaCB = animaCB;
			anima.m_pAnimationPaht = animaCB->getAnimationPath();
			m_vecAnimaControl.push_back(anima);
		}
		pNodeCB = dynamic_cast<osg::NodeCallback*>(animaCB->getNestedCallback());
	}
	traverse(node);
}

// 
AnimationPathFinder::AnimationPathFinder()
{

}

AnimationPathFinder::~AnimationPathFinder()
{

}

std::vector<osg::ref_ptr<osg::AnimationPath> > AnimationPathFinder::findAnimaPaths(osg::Node* node)
{
	std::vector<osg::ref_ptr<osg::AnimationPath> > vecPaths;
	vecPaths.clear();
	if (node)
	{
		AnimationPahtVisitor visitor;
		node->accept(visitor);
		vecPaths = visitor.getAnimaPath();
	}

	return vecPaths;
}

std::vector<osg::ref_ptr<osg::AnimationPathCallback> > AnimationPathFinder::findAnimaCBs(osg::Node* node)
{
	std::vector<osg::ref_ptr<osg::AnimationPathCallback> > vecCBs;
	vecCBs.clear();
	if (node)
	{
		AnimationPahtVisitor visitor;
		node->accept(visitor);
		vecCBs = visitor.getAnimaCB();
	}

	return vecCBs;
}

std::vector<AnimationControl> AnimationPathFinder::findAnimationControls(osg::Node* node)
{
	std::vector<AnimationControl> vecControls;
	vecControls.clear();
	if (node)
	{
		AnimationPahtVisitor vistor;
		node->accept(vistor);
		vecControls = vistor.getAnimaControl();
	}

	return vecControls;
}
