//
// File: AnimationControl.h
// Author:lyk
// Date: 2016/02/24
// Desc: ¶¯»­Â·¾¶¿ØÖÆ
//
#ifndef ANIMATIONCONTROL_H
#define ANIMATIONCONTROL_H

#include <osg/Transform>
#include <osg/AnimationPath>
#include "Export.h"

class ANIMATION_EXPORT AnimationControl
{
public:
	AnimationControl();
	~AnimationControl();
	
	void play();
	void playReverse();
	void pause();
	void resume();
	void stop();
	void jumpToTime(double time);

public:
	osg::ref_ptr<osg::Transform> m_pNode;
	osg::ref_ptr<osg::AnimationPath> m_pAnimationPaht;
	osg::ref_ptr<osg::AnimationPathCallback> m_pAnimaCB;
};

#endif // ANIMATIONCONTROL_H
