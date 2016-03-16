//
// File: Cordon.h
// Author:lyk
// Date: 2016/03/04
// Desc: ������
// Example: Cordon* pCordon = new Cordon;
//          pCordon->setCordonResource("jiejie.jpg", "dunzi.ive");
//          pCordon->addCardon(osg::Vec3(21,3,45));
//
#ifndef CORDON_H
#define CORDON_H

#include <osg/Vec3>
#include <osg/MatrixTransform> 
#include "Export.h"

class MODELTOOLS_EXPORT Cordon : public osg::MatrixTransform
{
public:
	Cordon();
	~Cordon();

	// ���þ�������Ҫ����Դ��strImage��ͼƬ��Դ��strNode�����ӵ�ģ��
	void setCordonResource(const std::string& strImage,
		const std::string& strNode);

	// �����ߵ�λ�ã������Ƕ��
	void addCardon(const osg::Vec3& pos);

private:
	osg::ref_ptr<osg::Node> m_pCardonNode;	
	osg::ref_ptr<osg::Image> m_pCardonImage;
	osg::ref_ptr<osg::Vec3Array> m_cordonLine;
	std::string m_strDunziPath;
	std::string m_strImagePath;
};

#endif // CORDON_H
