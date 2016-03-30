//
// File: SceneTreeWidget.h
// Author:lyk
// Date: 2016/03/30
// Desc: 场景树，之所以重写是为了添加右键菜单
//
#ifndef SCENETREEWIDGET_H
#define SCENETREEWIDGET_H

#include <QTreeWidget>
#include <QMouseEvent>

class SceneTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	SceneTreeWidget(QWidget *parent);
	~SceneTreeWidget();

protected:
	virtual void mousePressEvent(QMouseEvent* event);
};

#endif // SCENETREEWIDGET_H
