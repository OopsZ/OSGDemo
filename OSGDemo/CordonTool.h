//
// File: CordonTool.h
// Author:lyk
// Date: 2016/03/04
// Desc: ��Ӿ�����
//
#ifndef CordonTool_H
#define CordonTool_H

#include <QObject>
#include "PickModel.h"
#include "Cordon.h"

class CordonTool : public QObject, public PickModel
{
	Q_OBJECT
public:
	CordonTool(QObject* parent = NULL);
	~CordonTool();

	// �����߲���
	void beginCordon();
	void endCordon();
	void deleteCordonByName(const std::string& name);

protected:
	virtual void mouseLeftClicked(osg::Vec3& pos);
	virtual void doubleClicked();

signals:
	void signalFinishedCordon();

private:
	osg::ref_ptr<Cordon> m_pCordon;
};

#endif // CordonTool_H
