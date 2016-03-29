//
// File: CustomRightMenu.h
// Author:lyk
// Date: 2016/03/29
// Desc: 自定义右键菜单，目的是利用focusOutEvent，
//       自己失去焦点时消失
//
#ifndef CUSTOMRIGHTMENU_H
#define CUSTOMRIGHTMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class CustomRightMenu : public QWidget
{
	Q_OBJECT

public:
	CustomRightMenu(QWidget *parent = NULL);
	~CustomRightMenu();

	void addAction(QPushButton* item);

protected:
	virtual void focusOutEvent(QFocusEvent* e);

private:
	QVBoxLayout* m_pLayout;
};

#endif // CUSTOMRIGHTMENU_H
