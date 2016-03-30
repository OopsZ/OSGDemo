#include "SceneTreeItem.h"
#include <osg/Group>

SceneTreeItem::SceneTreeItem(QTreeWidgetItem* parent)
	: TreeWidgetItem(parent)
{
	QPushButton* btn = new QPushButton("highLight");
	btn->setCheckable(true);
	connect(btn, SIGNAL(clicked(bool)), this,SLOT(slotHighLight(bool)));
	m_pMenu->addAction(btn);

	btn = new QPushButton("transparent");
	btn->setCheckable(true);
	connect(btn, SIGNAL(clicked(bool)), this, SLOT(slotTransParent(bool)));
	m_pMenu->addAction(btn);
}

SceneTreeItem::~SceneTreeItem()
{

}

void SceneTreeItem::setNode(osg::Node* node)
{
	m_pNode = node;

	traveNode(this, node);
}

void SceneTreeItem::traveNode(QTreeWidgetItem* root, osg::Node* node)
{
	if (root == NULL || node == NULL)
	{
		return;
	}

	osg::Group* pGroup = node->asGroup();
	if (pGroup == NULL)
	{
		return;
	}

	for (int i = 0; i < pGroup->getNumChildren(); ++i)
	{
		osg::ref_ptr<osg::Node> pNode = pGroup->getChild(i);
		if (pNode)
		{
			QString strName = QString::fromStdString(pNode->getName());
			SceneTreeItem* pItem = new SceneTreeItem(root);
			pItem->setText(0, strName);
			pItem->setNode(pNode);
		}
	}
}

void SceneTreeItem::slotHighLight()
{

}

void SceneTreeItem::slotTransParent()
{

}
