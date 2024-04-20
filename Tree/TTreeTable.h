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
	int countpos, lvl;
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
	void Reset()
	{
		while (!st.empty()) st.pop();
		pCurr = pRoot;
		while (pCurr != nullptr)
		{
			st.push(pCurr);
			pCurr = pCurr->pLeft;
		}
		pCurr = st.top();
		countpos = 0;
	}
	void GoNext()
	{
		st.pop();
		if (pCurr->pRight != nullptr)
		{
			pCurr = pCurr->pRight;
			while (pCurr != nullptr)
			{
				st.push(pCurr);
				pCurr = pCurr->pLeft;
			}
			pCurr = st.top();
		}
		else if (!st.empty())pCurr = st.top();
		countpos++;
	}
	bool IsEnd()
	{
		return countpos == dataCount;
	}
	void DeleteTreeTab(TTreeNode* pNode)
	{
		if (pNode != nullptr)
		{
			DeleteTreeTab(pNode->pLeft);
			DeleteTreeTab(pNode->pRight);
			delete pNode;
		}
	}
	~TTreeTable() 
	{
		DeleteTreeTab(pRoot);
	}
	void PrintTable(std::ostream &os,TTreeNode * pNode)
	{
		if (pNode != nullptr)
		{
			for (int i = 0; i < lvl; i++)
			{
				os << " ";
			}
			os << pNode->rec.key<<std::endl;
			lvl++;
			PrintTable(os, pNode->pRight);
			PrintTable(os, pNode->pLeft);
			lvl--;

		}
	}
	


};

