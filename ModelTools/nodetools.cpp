#include "nodetools.h"
#include <osg/Material>
#include "Lib.h"

NodeTools::NodeTools()
{

}

NodeTools::~NodeTools()
{

}

void NodeTools::setHighLightOn(osg::Node* node, osg::Vec4& color)
{
	if (node == NULL)
	{
		return;
	}

	osg::StateSet* state = node->getOrCreateStateSet();
	osg::Material* material = dynamic_cast<osg::Material*>(state->getAttribute(
		osg::StateAttribute::MATERIAL));
	if (material == NULL)
	{
		material = new osg::Material;
	}

	material->setAmbient(osg::Material::FRONT_AND_BACK, color);
	material->setDiffuse(osg::Material::FRONT_AND_BACK, color);
	material->setEmission(osg::Material::FRONT_AND_BACK, color);
	material->setSpecular(osg::Material::FRONT_AND_BACK, color);

	state->setAttributeAndModes(material,
		osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
}

void NodeTools::setHighLightOff(osg::Node* node)
{
	if (node == NULL)
	{
		return;
	}

	osg::StateSet* state = node->getOrCreateStateSet();
	osg::Material* material = dynamic_cast<osg::Material*>(state->getAttribute(
		osg::StateAttribute::MATERIAL));
	state->setAttribute(material);
}
