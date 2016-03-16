#include "Cordon.h"
#include <osg/Geode>
#include <osg/StateSet>
#include <osgDB/ReadFile>
#include <osg/ShapeDrawable>
#include <osg/Material>
#include <osg/Texture2D>
#include "Lib.h"

Cordon::Cordon()
{
	m_cordonLine = new osg::Vec3Array;
}

Cordon::~Cordon()
{

}

void Cordon::setCordonResource(const std::string& strImage,
							  const std::string& strNode)
{
	m_strDunziPath = strNode;
	m_strImagePath= strImage;

	m_pCardonImage = osgDB::readImageFile(m_strImagePath);
	m_pCardonNode = osgDB::readNodeFile(m_strDunziPath);
}

void Cordon::addCardon( const osg::Vec3& pos )
{
	m_cordonLine->push_back(pos);
	if (m_cordonLine->size()==1)
	{
		osg::Vec3 currentPoint = (*m_cordonLine)[0];					 

		std::string nodeName = "Cordon:DUNZI";

		osg::ref_ptr<osg::MatrixTransform> matrix = new osg::MatrixTransform;
		matrix->addChild(dynamic_cast<osg::Node*>(
			m_pCardonNode->clone(osg::CopyOp::DEEP_COPY_ALL)));				
		matrix->setMatrix(osg::Matrix::translate(currentPoint));
		matrix->setName(nodeName);
		matrix->setNodeMask(0x1);

		addChild(matrix);	
	}
	else if (m_cordonLine->size()>=2)
	{
		osg::Vec3 currentPoint = (*m_cordonLine)[m_cordonLine->size() - 1];
		osg::Vec3 prePoint = (*m_cordonLine)[m_cordonLine->size() - 2];

		osg::Vec3 dir = currentPoint - prePoint;
		float length = dir.length() / 0.49;

		osg::Vec3 point1 = prePoint + osg::Vec3(0, 0, 1.225);
		osg::Vec3 point2 = currentPoint + osg::Vec3(0, 0, 1.225);
		osg::Vec3 point3 = currentPoint + osg::Vec3(0, 0, 1.065);
		osg::Vec3 point4 = prePoint + osg::Vec3(0, 0, 1.065);

		osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;

		texture->setImage(m_pCardonImage);
		texture->setDataVariance(osg::Object::DYNAMIC);
		texture->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP_TO_BORDER);
		texture->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::REPEAT);

		//���ݸ����ĸ��㣬����һ��ƽ�棬�������ͼƬ
		osg::ref_ptr<osg::Geometry> gm = new osg::Geometry;

		//�ĸ�����
		osg::ref_ptr<osg::Vec3Array> gmVertex = new osg::Vec3Array;	
		gmVertex->push_back(point1);
		gmVertex->push_back(point2);
		gmVertex->push_back(point3);
		gmVertex->push_back(point4);
		gm->setVertexArray(gmVertex);

		////������������
		osg::ref_ptr<osg::Vec2Array> gmCoord = new osg::Vec2Array;
		gmCoord->push_back(osg::Vec2(0.0, 1.0));
		gmCoord->push_back(osg::Vec2(-length, 1.0f));
		gmCoord->push_back(osg::Vec2(-length, 0.0f));
		gmCoord->push_back(osg::Vec2(0.0f, 0.0f));
		gm->setTexCoordArray(0, gmCoord);

		//��������
		gm->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
		//��������
		gm->getOrCreateStateSet()->setTextureAttributeAndModes(0,
			texture, osg::StateAttribute::ON);	

		osg::ref_ptr<osg::StateSet> stateset = gm->getStateSet();
		stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
		stateset->setDataVariance(osg::Object::DYNAMIC);	

		std::string jingjietiaoname = "Cordon:JJT";			

		//����һ��GEODE��������GM���������ֱ�־����ģ�ͼ��볡��
		osg::ref_ptr<osg::Geode> pGeode = new osg::Geode;
		pGeode->addDrawable(gm.get());
		pGeode->setName(jingjietiaoname);
		osg::ref_ptr<osg::MatrixTransform> videoMatrix = new osg::MatrixTransform;
		videoMatrix->addChild(pGeode.get());	
		videoMatrix->setName(jingjietiaoname);
		videoMatrix->setNodeMask(0x1);

		addChild(videoMatrix.get());

		std::string nodeName = "Cordon:DUNZI";
		osg::ref_ptr<osg::MatrixTransform> matrix = new osg::MatrixTransform;
		matrix->addChild(dynamic_cast<osg::Node*>(m_pCardonNode->clone(osg::CopyOp::DEEP_COPY_ALL)));				
		matrix->setMatrix(osg::Matrix::translate(currentPoint));
		matrix->setName(nodeName);
		matrix->setNodeMask(0x1);

		addChild(matrix.get());				
	}
}
