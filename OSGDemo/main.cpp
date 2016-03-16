#include "osgdemo.h"
#include <QApplication>
#include "Lib.h"
#include "FileUtils.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FileUtils::ins()->init(QApplication::applicationDirPath()
		.append("/../Data").toLocal8Bit().data());

	OSGDemo w;
	w.show();
	return a.exec();
}
