#ifndef FINDNODE_H
#define FINDNODE_H

#include <osg/NodeVisitor>
#include <osg/Node>
#include <osg/observer_ptr>
#include "Export.h"

class MODELTOOLS_EXPORT FindNode : public osg::NodeVisitor
{
public:
	FindNode(const std::string& name);
	~FindNode();

	osg::ref_ptr<osg::Node> getNode(){ return m_pNode; }

protected:
	virtual void apply(osg::Node& node);

private:
	std::string m_strName;
	osg::observer_ptr<osg::Node> m_pNode;
};

#endif // FINDNODE_H
