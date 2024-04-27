#pragma once
#include "TTreeTable.h"
#define  H_OK 0
#define  H_INC 1
#define  H_DEC -1


class AVLTree:public TTreeTable
{
protected:
	int InsBalTree(TTreeNode*& pNode, TRecord rec)
	{
		int res = H_OK; efficiency++;
		if (pNode == nullptr)
		{
			pNode = new TTreeNode(rec);
			res = H_INC; dataCount++;
		
		}
		else if (pNode->rec.key > rec.key)
		{
			int tmp = InsBalTree(pNode->pLeft, rec);
			if (tmp == H_INC)
			{
				//res = LeftBalance(pNode);
			}
		}
		else if (pNode->rec.key < rec.key) {
			int tmp = InsBalTree(pNode->pRight, rec);
			if (tmp == H_INC)
			{
				//res = RightBalance(pNode);
			}
		}
		return res;
	}
public:
	bool Insert(TRecord rec)
	{
		bool res = Find(rec.key);
		if (res == true)
		{
			return false;
		}
		else {
			InsBalTree(pRoot, rec);
		}
	}
};

