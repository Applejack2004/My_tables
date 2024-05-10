#pragma once
#include "TTreeTable.h"


class AVLTree:public TTreeTable
{
protected:
	int Left_Balance(TTreeNode*& pNode)
	{
		efficiency++; int res = H_OK;
		switch (pNode->bal)
		{
		case BalRight:
			pNode->bal = BalOK; res = H_OK; break;
		case BalOK:
			pNode->bal = BalLeft; res = H_INC; break;
		case BalLeft:
			TTreeNode *p1, *p2;
			p1 = pNode->pLeft;
			if (p1->bal == BalLeft)
			{
				pNode->pLeft = p1->pRight;
				p1->pRight = pNode;
				pNode->bal = BalOK;
				pNode = p1;
				pNode->bal = BalOK;
			}
			else
			{
				p2 = p1->pRight;
				p1->pRight = p2->pLeft;
				pNode->pLeft = p2->pRight;
				p2->pLeft = p1;
				p2->pRight = pNode;
				if (p2->bal = BalRight)
				{
					p1->bal = BalLeft;
					pNode->bal = BalOK;

				}
				else {
					p1->bal = BalOK;
					pNode->bal = BalRight;
				}
				pNode = p2; pNode->bal = BalOK;
				res = H_OK;
			}
			break;


		default:
			break;
		}
		return res;
	}
	int Right_Balance(TTreeNode*& pNode)
	{
		efficiency++;
		int res = H_OK;
		switch (pNode->bal)
		{
		case BalLeft:
			pNode->bal = BalOK;
			res = H_OK;
			break;
		case BalOK:
			pNode->bal = BalRight;
			res = H_INC;
			break;
		case BalRight:
			TTreeNode* p1, * p2;
			p1 = pNode->pRight;
			if (p1->bal == BalRight)
			{
				pNode->pRight = p1->pLeft;
				p1->pLeft = pNode;
				pNode->bal = BalOK;
				pNode = p1;
				pNode->bal = BalOK;
			}
			else
			{
				p2 = p1->pLeft;
				p1->pLeft = p2->pRight;
				pNode->pRight = p2->pLeft;
				p2->pRight = p1;
				p2->pLeft = pNode;
				if (p2->bal == BalLeft)
				{
					p1->bal = BalRight;
					pNode->bal = BalOK;
				}
				else
				{
					p1->bal = BalOK;
					pNode->bal = BalLeft;
				}
				pNode = p2;
				pNode->bal = BalOK;
				res = H_OK;
			}
			break;
		default:
			break;
		}

		return res;
	}
	int InsBalTree(TTreeNode*& pNode, TRecord rec)
	{
		int res = H_OK; efficiency++;
		if (pNode == nullptr)
		{
			pNode = new TTreeNode(rec);
			res = H_INC; dataCount++;//
		
		}
		else if (pNode->rec.key > rec.key)
		{
			int tmp = InsBalTree(pNode->pLeft, rec);
			if (tmp == H_INC)
			{
				res = Left_Balance(pNode);
			}
		}
		else if (pNode->rec.key < rec.key) {
			int tmp = InsBalTree(pNode->pRight, rec);
			if (tmp == H_INC)
			{
				res = Right_Balance(pNode);
			}
		}
		return res;
	}
	int RemoveMin(TTreeNode*& pNode)
	{
		int res = H_OK;
		if (pNode->pLeft == nullptr)
		{
			pNode = pNode->pRight;
			res = H_DEC;
		}
		else
		{
			res = RemoveMin(pNode->pLeft);
			if (res != H_OK)
			{
				res = Right_Balance(pNode);
			}
			

			
		}
		return res;
	}
	TTreeNode* FindMin(TTreeNode* pNode) {
		if (pNode == nullptr) {
			return nullptr; // Пустое дерево
		}
		while (pNode->pLeft != nullptr) {
			pNode = pNode->pLeft; // Двигаемся влево, пока не дойдем до самого левого узла
		}
		return pNode; // Возвращаем узел с минимальным ключом
	}
	int DeleteRec(TTreeNode*& pNode, TKey key)
	{
		int res;
		if (pNode == nullptr) return H_OK;
		efficiency++;
		if (pNode->rec.key > key)
		{
			 res = DeleteRec(pNode->pLeft, key);
			if (res != H_OK)
			{
				res = Right_Balance(pNode);
			}
			else if (pNode->rec.key<key)
			{
				res = DeleteRec(pNode->pRight, key);
				if (res != H_OK)
				{
					res = Left_Balance(pNode);
				}
			}
		}
		else
		{
			dataCount--;
			if (pNode->pLeft == nullptr && pNode->pRight == nullptr)
			{
				delete pNode;
				pNode = nullptr;
				 res = H_DEC;
			}
			else if (pNode->pRight == nullptr && pNode->pLeft != nullptr)
			{
				pNode->rec = pNode->pLeft->rec;
				delete pNode->pLeft;
				pNode->pLeft = nullptr;
				pNode->bal = BalOK; 
				res = H_DEC;
			}
			else if (pNode->pRight != nullptr && pNode->pLeft == nullptr)
			{
				pNode->rec = pNode->pRight->rec;
				delete pNode->pRight;
				pNode->pRight = nullptr;
				pNode->bal = BalOK;
				res = H_DEC;
			}
			else 
			{
				TTreeNode* l, * r;
				l = pNode->pLeft;
				r = pNode->pRight;
				TTreeNode* min = FindMin(r);
				res = RemoveMin(min);
				pNode->rec = min->rec;
				delete min;
				pNode->pLeft = l;
				pNode->pRight = r;
				if (res != H_OK)
				{
					res = Left_Balance(pNode);
				}

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
	bool Delete(TKey key)
	{
		if (!Find(key))
		{
			return false;
		}
		else 
		{
			DeleteRec(pRoot, key);
			return  true;
		  
	    }     
	}
};

