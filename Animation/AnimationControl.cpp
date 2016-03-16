#include "AnimationControl.h"
#include <osg/MatrixTransform>
#include "Lib.h"

AnimationControl::AnimationControl()
{

}

AnimationControl::~AnimationControl()
{

}

void AnimationControl::play()
{
	if (!m_pNode.valid() || !m_pAnimationPaht.valid() || !m_pAnimaCB.valid())
	{
		return;
	}

	m_pNode->removeUpdateCallback(m_pAnimaCB);
	m_pAnimaCB->setPause(true);
	m_pAnimaCB->reset();
	m_pAnimaCB->setAnimationPath(m_pAnimationPaht);
	m_pAnimaCB->setPause(false);
	m_pNode->addUpdateCallback(m_pAnimaCB);
}

void AnimationControl::playReverse()
{
	if (!m_pNode.valid() || !m_pAnimationPaht.valid() || !m_pAnimaCB.valid())
	{
		return;
	}
}

void AnimationControl::pause()
{
	if (!m_pNode.valid() || !m_pAnimationPaht.valid() || !m_pAnimaCB.valid())
	{
		return;
	}
	m_pAnimaCB->setPause(true);
}

void AnimationControl::resume()
{
	if (!m_pNode.valid() || !m_pAnimationPaht.valid() || !m_pAnimaCB.valid())
	{
		return;
	}
	m_pAnimaCB->setPause(false);
}

void AnimationControl::stop()
{
	if (!m_pNode.valid() || !m_pAnimationPaht.valid() || !m_pAnimaCB.valid())
	{
		return;
	}

	m_pAnimaCB->reset();
	m_pAnimaCB->setPause(true);
}

void AnimationControl::jumpToTime(double time)
{
	if (!m_pNode.valid() || !m_pAnimationPaht.valid() || !m_pAnimaCB.valid())
	{
		return;
	}

	osg::Matrix mat;
	m_pAnimationPaht->getMatrix(time, mat);
	osg::MatrixTransform* trans = m_pNode->asMatrixTransform();
	if (trans)
	{
		trans->setMatrix(mat);
	}
}
