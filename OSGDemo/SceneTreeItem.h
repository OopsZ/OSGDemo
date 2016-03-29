//
// File: SceneTreeItem.h
// Author:lyk
// Date: 2016/03/29
// Desc: �������ڵ�
//
#ifndef SCENETREEITEM_H
#define SCENETREEITEM_H

#include "TreeWidgetItem.h"
#include <osg/Node>
#include <osg/observer_ptr>

class SceneTreeItem : public TreeWidgetItem
{
	Q_OBJECT

public:
	SceneTreeItem(QTreeWidgetItem* parent = NULL);
	~SceneTreeItem();

	void setNode(osg::Node* node);
	void traveNode(QTreeWidgetItem* root, osg::Node* node);

private slots:
	void slotHighLight();
	void slotTransParent();

private:
	// �˴���ֻΪ����ʹ�ã����������ü���
	osg::observer_ptr<osg::Node> m_pNode;
};

#endif // SCENETREEITEM_H
