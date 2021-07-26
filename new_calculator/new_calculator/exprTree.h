#pragma once
#include "exprNode.h"
#include "value_c.h"
class exprTree
{
public:
	exprTree();
	~exprTree();
	int build(value_c *&head);
private:
	int buildTree(value_c *&head, exprNode *&root, bool isPTH = false);
	int buildTreeEnd(vector<exprNode *> &crtCacheOperands, vector<exprNode *> &crtCacheOperators, exprNode *&root);
	exprNode *m_theRoot;
};

