#pragma once
#include "TTable.h"
#include <stack>
#define  H_OK 0
#define  H_INC 1
#define  H_DEC -1
#define  BalRight 1
#define  BalOK 0
#define  BalLeft -1

struct TTreeNode {
	TRecord rec;
	TTreeNode* pLeft, * pRight;
	int bal;
	TTreeNode(const TRecord& _rec)
	{
		rec = _rec;
		pLeft = nullptr;
		pRight = nullptr;
		bal = BalOK;
	}
};


class TTreeTable:public TTable
{
protected:

	TTreeNode* pRoot, * pCurr, * pPrev;
	std::stack<TTreeNode*> st;
	int countpos{}, lvl{};
	

public:

	TTreeTable()
	{
		pRoot = nullptr;
		pCurr = nullptr;
		pPrev = nullptr;
		countpos = 0; lvl = 0;
	}

	bool Find(TKey key)
	{
		if (pCurr != nullptr)
		{
			if (pCurr->rec.key == key)
			{
				return true;
			}
		}
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
		while (!st.empty())
		{
			st.pop();
		}
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
		if (pCurr==nullptr || IsEnd())
		{
			throw std::exception();
		}
		if (!st.empty())
		{
			st.pop();
		}
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
		else if (!st.empty())
		{
			pCurr = st.top();
		}
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

	void PrintTable(std::ostream& os, TTreeNode* pNode)
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

	bool IsFull() const { return false; } ;
    TRecord GetCurrentRecord() {return pCurr->rec;};
	void SetCurrentRecord(TRecord record) 
	{ 
		pCurr->rec.key = record.key; 
		pCurr->rec.value = record.value;
	};


	TKey GetRightKey(TKey key)
	{
		Find(key);
		if (pCurr->pRight == nullptr)
		{
			return -1;
		}
		else
		{
			return pCurr->pRight->rec.key;
		}
	}
	TKey GetLeftKey(TKey key)
	{
		Find(key);
		if (pCurr->pLeft == nullptr)
		{
			return -1;
		}
		else
		{
			return pCurr->pLeft->rec.key;
		}
	}
	TKey GetRootKey()
	{
		return pRoot->rec.key;
	}
};

