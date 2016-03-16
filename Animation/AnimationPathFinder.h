//
// File: AnimationPathFinder.h
// Author:lyk
// Date: 2016/02/24
// Desc: 通过模型查找其动画路径
//
#ifndef ANIMATIONPATHFINDER_H
#define ANIMATIONPATHFINDER_H
#include <osg/Node>
#include <osg/NodeVisitor>
#include <osg/AnimationPath>
#include <osg/Transform>
#include "AnimationControl.h"
#include "Export.h"

class ANIMATION_EXPORT AnimationPahtVisitor : public osg::NodeVisitor
{
public:
	AnimationPahtVisitor();
	~AnimationPahtVisitor();

	std::vector<osg::ref_ptr<osg::AnimationPath> > getAnimaPath();
	std::vector<osg::ref_ptr<osg::AnimationPathCallback> > getAnimaCB();
	std::vector<AnimationControl> getAnimaControl();

	virtual void apply(osg::Transform& node);

private:
	std::vector<osg::ref_ptr<osg::AnimationPath> > m_vecAnimaPath;
	std::vector<osg::ref_ptr<osg::AnimationPathCallback> > m_vecAnimaCB;
	std::vector<AnimationControl> m_vecAnimaControl;
};

class AnimationPathFinder
{
public:
	AnimationPathFinder();
	~AnimationPathFinder();

	std::vector<osg::ref_ptr<osg::AnimationPath> > findAnimaPaths(osg::Node* node);
	std::vector<osg::ref_ptr<osg::AnimationPathCallback> > findAnimaCBs(osg::Node* node);
	std::vector<AnimationControl> findAnimationControls(osg::Node* node);

private:
	
};

#endif // ANIMATIONPATHFINDER_H
