#pragma once
#include<vector>
#include "value_c.h"
using namespace std;
class exprNode
{
public:
	exprNode();
	~exprNode();
	vector<exprNode *> m_subExprNode;
	void setData(value_c *vc);
	value_c * getData();
	void setChild(vector<exprNode *> &theChilds);
	void addChild(exprNode *theChild);
private:
	value_c *m_vc;
};

