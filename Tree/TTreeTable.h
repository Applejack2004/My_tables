#pragma once
#include "TTable.h"
#include <stack>
struct TTreeNode {
	TRecord rec;
	TTreeNode* pLeft, * pRight;
	TTreeNode(const TRecord& _rec)
	{
		rec = _rec;
		pLeft = nullptr;
		pRight = nullptr;
	}
};
class TTreeTable:public TTable
{
protected:
	TTreeNode* pRoot, * pCurr, * pPrev;
	std::stack<TTreeNode*> st;
public:
	TTreeTable()
	{
		pRoot = nullptr;
		pCurr = nullptr;
		pPrev = nullptr;
	}

	bool Find(TKey key)
	{
		pCurr = pRoot; pPrev = nullptr;
		while (pCurr != nullptr)
		{
			efficiency++;
			if (pCurr->rec.key == key) break;
			else {
				pPrev = pCurr;
				if (pCurr->rec.key > key)
				{
					pCurr = pCurr->pLeft;
				}
				else {
					pCurr = pCurr->pRight;
				}
			}
		}
		if (pCurr != nullptr) {
			return true;
		}
		else {
			pCurr = pPrev;
			return false;
		}

    }
	bool Insert(TRecord _rec)
	{
		if (Find(_rec.key))
		{
			return false;
		}
		else 
		{
			TTreeNode* newNode = new TTreeNode(_rec);
			if (pRoot == nullptr)
			{
				pRoot = newNode;
			
			}
			else
			{
				if (pCurr->rec.key > _rec.key)
				{
					pCurr->pLeft = newNode;

				}
				else 
				{
					pCurr->pRight = newNode;
				}
			}
			dataCount++;
			return true;
		}
		
		
	}
	bool Delete(TKey key)
	{
		if (!Find(key)) return false;
		TTreeNode* pDel = pCurr;
		if (pCurr->pRight == nullptr)
		{
			if (pPrev == nullptr)  pRoot = pRoot->pLeft;
			else
			{
				if (pCurr->rec.key > pPrev->rec.key)
				{
					pPrev->pRight = pCurr->pLeft;
				}
				else
				{
					pPrev->pLeft = pCurr->pLeft;
				}
			}
		
		}
		else if(pCurr->pLeft==nullptr)
		{
			if (pPrev == nullptr)  pRoot = pRoot->pRight;
			else
			{
				if (pCurr->rec.key > pPrev->rec.key)
				{
					pPrev->pRight = pCurr->pRight;
				}
				else
				{
					pPrev->pLeft = pCurr->pRight;
				}
			}

		}
		else 
		{
			TTreeNode* tmp = pCurr->pLeft;
			pPrev = pCurr;
			while (tmp->pRight != nullptr)
			{
				efficiency++;
				pPrev = tmp;
				tmp = tmp->pRight;
			}
			pCurr->rec = tmp->rec;
			if (pPrev != pCurr)
			{
				pPrev->pRight = tmp->pLeft;
			}
			else
			{
				pPrev->pLeft = tmp->pLeft;
			}
			pDel = tmp;
		}
		efficiency++;
		delete pDel;
		dataCount--;
		return true;
	}


};

