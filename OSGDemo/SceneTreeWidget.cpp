#include "SceneTreeWidget.h"
#include "SceneTreeItem.h"

SceneTreeWidget::SceneTreeWidget(QWidget *parent)
	: QTreeWidget(parent)
{

}

SceneTreeWidget::~SceneTreeWidget()
{

}

void SceneTreeWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::RightButton)
	{
		SceneTreeItem *item = dynamic_cast<SceneTreeItem *>(itemAt(event->pos()));
		if (item)
		{
			item->showMenu(event->globalPos());
		}
	}

	QTreeWidget::mousePressEvent(event);
}
