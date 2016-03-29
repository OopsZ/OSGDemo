//
// File: SceneTreeItem.h
// Author:lyk
// Date: 2016/03/29
// Desc: 场景树节点
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
	// 此处，只为引用使用，不增加引用计数
	osg::observer_ptr<osg::Node> m_pNode;
};

#endif // SCENETREEITEM_H
