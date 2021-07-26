#include "exprNode.h"
exprNode::exprNode()
{

}
exprNode::~exprNode()
{

}

void exprNode::setData(value_c *vc)
{
	m_vc = vc;
}
value_c * exprNode::getData()
{
	return m_vc;
}
void exprNode::setChild(vector<exprNode *> &theChilds)
{
	m_subExprNode = theChilds;
}

void exprNode::addChild(exprNode *theChild)
{
	m_subExprNode.push_back(theChild);
}