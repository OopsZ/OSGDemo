//
// File: fileutils.h
// Author:lyk
// Date: 2015/12/28
// Desc: 路径的统一获取方式
//
#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <iostream>
#include <string>
#include "Export.h"

////////////////////////////////////////////////
// 使用方式为在main函数的入口处，调用init,
// 所得目录即为根目录，之后获取的目录都以此为基目录
// FileUtils::ins()->init("D:/project/");
////////////////////////////////////////////////
class COMMON_EXPORT FileUtils
{
public:
	static FileUtils* ins();
	static void del();

	void init(const std::string& name);
	std::string getPath(const std::string& name);

private:
	FileUtils();
	~FileUtils();

private:
	static FileUtils* m_pIns;
	std::string m_strRoot;
};

#endif // FILEUTILS_H
