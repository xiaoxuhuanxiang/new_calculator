#include "exprTree.h"
#include <iostream>
using namespace std;
exprTree::exprTree()
{

}

exprTree::~exprTree()
{

}

int exprTree::build(value_c *&head)
{
	return buildTree(head, m_theRoot);
}
int exprTree::buildTree(value_c *&head, exprNode *&root, bool isPTH)
{
	vector<exprNode *> crtCacheOperands;
	vector<exprNode *> crtCacheOperators;
	crtCacheOperands.reserve(10);
	crtCacheOperators.reserve(10);

	if (!head) return true;
	for (value_c *crt = head; crt; crt = crt->next)
	{
		ElementType crtType = crt->getElementType();
		if (crtType == VT_NUMBER)
		{
			exprNode *en = new exprNode();
			en->setData(crt);
			crtCacheOperands.push_back(en);
			if (!crt->next)
			{
				if (!buildTreeEnd(crtCacheOperands, crtCacheOperators, root)) return false;
				return true;
			}
		}
		else
		{
			if (global::isOperType(crtType))
			{
				if (crtCacheOperators.empty())
				{
					exprNode *op = new exprNode();
					op->setData(crt);
					crtCacheOperators.push_back(op);
				}
				else
				{
					exprNode *op = new exprNode();
					op->setData(crt);
					exprNode *oplast = crtCacheOperators.back();
					ElementType lastType = oplast->getData()->getElementType();
					ElementType crtType = op->getData()->getElementType();
					int prior1 = global::getOperPrior_type(lastType);
					int prior2 = global::getOperPrior_type(crtType);
					if (prior1 >= prior2)
					{
						int numOfOperands = global::getNumOfOperandsByOper(lastType);
						for (int iOpds = 0; iOpds < numOfOperands; ++iOpds)
						{
							if (crtCacheOperands.empty()) return false;
							oplast->addChild(crtCacheOperands.back());
							crtCacheOperands.pop_back();
						}
			
						crtCacheOperands.push_back(oplast);
						crtCacheOperators.pop_back();
						crtCacheOperators.push_back(op);
					}
					else
					{
						crtCacheOperators.push_back(op);
					}
				}
			}
			else if (crtType == VT_LPTH)
			{
				exprNode *en = 0;
				crt = crt->next;
				if(!buildTree(crt, en, true)) return false;
				crtCacheOperands.push_back(en);
				if (!crt->next)
				{
					if (!buildTreeEnd(crtCacheOperands, crtCacheOperators, root)) return false;
					return true;
				}
			}
			else if (crtType == VT_RPTH)
			{
				if (!isPTH) return false;
				else
				{
					if (!buildTreeEnd(crtCacheOperands, crtCacheOperators, root)) return false;
					head = crt;
					return true;
				}
			}
		}
	}

	return false;
}

int exprTree::buildTreeEnd(vector<exprNode *> &crtCacheOperands, vector<exprNode *> &crtCacheOperators, exprNode *&root)
{
	for (vector<exprNode *>::reverse_iterator rit = crtCacheOperators.rbegin();
		rit != crtCacheOperators.rend(); ++rit)
	{
		int numOfOperands = global::getNumOfOperandsByOper((*rit)->getData()->getElementType());
		for (int iOpds = 0; iOpds < numOfOperands; ++iOpds)
		{
			if (crtCacheOperands.empty()) return false;
			(*rit)->addChild(crtCacheOperands.back());
			crtCacheOperands.pop_back();
		}
		crtCacheOperands.push_back(*rit);
	}

	if (crtCacheOperands.size() != 1) return false;
	root = crtCacheOperands[0];
	return true;
}