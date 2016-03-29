#include "NodeTools.h"
#include <osg/Material>
#include <osg/BlendColor>
#include <osg/BlendFunc>
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

void NodeTools::setAlpha(osg::StateSet* ss, float alpha /*= 0.5*/,
						 osg::StateAttribute::GLModeValue value)
{
	if (!ss)
	{
		return;
	}

	ss->setDataVariance(osg::Object::DYNAMIC);

	osg::ref_ptr<osg::BlendColor> bc = dynamic_cast<osg::BlendColor*>(
		ss->getAttribute(osg::StateAttribute::BLENDCOLOR));
	if (!bc.valid())
	{
		bc = new osg::BlendColor(osg::Vec4(alpha, alpha, alpha, alpha));
	}
	osg::ref_ptr<osg::BlendFunc> bf = dynamic_cast<osg::BlendFunc*>(
		ss->getAttribute(osg::StateAttribute::BLENDFUNC));
	if (!bf.valid())
	{
		bf = new osg::BlendFunc;
	}
	bf->setSource(osg::BlendFunc::CONSTANT_COLOR);
	bf->setDestination(osg::BlendFunc::ONE_MINUS_CONSTANT_COLOR);

	ss->setMode(GL_BLEND, value);
	ss->setMode(GL_DEPTH_TEST, value);
	ss->setAttributeAndModes(bc, value);
	ss->setAttributeAndModes(bf, value);

	ss->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	ss->setRenderBinDetails(100, "RenderBin");
}

void NodeTools::clearAlpha(osg::StateSet* ss)
{
	if (!ss)
	{
		return;
	}

	ss->setDataVariance(osg::Object::DYNAMIC);

	osg::ref_ptr<osg::BlendColor> bc = dynamic_cast<osg::BlendColor*>(
		ss->getAttribute(osg::StateAttribute::BLENDCOLOR));
	if (bc.valid())
	{
		ss->removeAttribute(bc);
	}
	osg::ref_ptr<osg::BlendFunc> bf = dynamic_cast<osg::BlendFunc*>(
		ss->getAttribute(osg::StateAttribute::BLENDFUNC));
	if (bf.valid())
	{
		ss->removeAttribute(bf);
	}

	ss->setRenderingHint(osg::StateSet::OPAQUE_BIN);
	ss->setRenderBinDetails(-1, "RenderBin");
}
