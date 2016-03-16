#include "findnode.h"
#include "Lib.h"

FindNode::FindNode(const std::string& name)
:NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
m_strName(name)
{

}

FindNode::~FindNode()
{

}

void FindNode::apply( osg::Node& node )
{
	if (m_strName.compare(node.getName()) == 0)
	{
		m_pNode = &node;
		return;
	}
	traverse(node);
}
