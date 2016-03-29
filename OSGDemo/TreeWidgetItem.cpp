#include "TreeWidgetItem.h"

TreeWidgetItem::TreeWidgetItem(QTreeWidget* parent)
	: QTreeWidgetItem(parent)
{
	m_pMenu = new CustomRightMenu;
	//m_pMenu->hide();
}

TreeWidgetItem::TreeWidgetItem(QTreeWidgetItem* parent)
	: QTreeWidgetItem(parent)
{
	m_pMenu = new CustomRightMenu;
	//m_pMenu->hide();
}

TreeWidgetItem::~TreeWidgetItem()
{
	delete m_pMenu;
}

void TreeWidgetItem::showMenu(const QPoint& pos)
{
	m_pMenu->move(pos);
	m_pMenu->show();
	m_pMenu->setFocus();
}
