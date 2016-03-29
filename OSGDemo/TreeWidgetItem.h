//
// File: TreeWidgetItem.h
// Author:lyk
// Date: 2016/03/29
// Desc: ×Ô¶¨Òåtree item
//
#ifndef TREEWIDGETITEM_H
#define TREEWIDGETITEM_H

#include <QObject>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include "CustomRightMenu.h"

class TreeWidgetItem : public QObject, public QTreeWidgetItem
{
	Q_OBJECT

public:
	TreeWidgetItem(QTreeWidget* parent);
	TreeWidgetItem(QTreeWidgetItem* parent);
	~TreeWidgetItem();

	void showMenu(const QPoint& pos);

protected:
	CustomRightMenu* m_pMenu;
};

#endif // TREEWIDGETITEM_H
