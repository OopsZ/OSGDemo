//
// File: fileutils.h
// Author:lyk
// Date: 2015/12/28
// Desc: ·����ͳһ��ȡ��ʽ
//
#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <iostream>
#include <string>
#include "Export.h"

////////////////////////////////////////////////
// ʹ�÷�ʽΪ��main��������ڴ�������init,
// ����Ŀ¼��Ϊ��Ŀ¼��֮���ȡ��Ŀ¼���Դ�Ϊ��Ŀ¼
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
