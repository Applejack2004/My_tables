#pragma once
#include "THashTable.h"
#include <list>
class TListHash:public THashTable
{
protected:
	std::list<TRecord>* pList;
	int size, CurrList;
	std::list<TRecord>::iterator pCurr;
public:
	TListHash(int _size=MAX_SIZE)
	{
		size = _size;
		pList = new std::list<TRecord>[size];
	}
	~TListHash()
	{
		delete[] pList;
	}
	bool Find(TKey _key)
	{
		CurrList = HashFunc(_key)%size;
		for (pCurr = pList[CurrList].begin(); pCurr != pList[CurrList].end(); pCurr++)
		{
			efficiency++;
			if (pCurr->key == _key)
			{
				return true;
			}
		}
		return false;


	}
	bool Insert(TRecord record)
	{
		if(Find(record.key))
		{
			throw std::exception();
		}
		else 
		{
			pList[CurrList].push_front(record);
			dataCount++;
		}
	}
	bool Delete(TKey _key)
	{
		if (!Find(_key))
		{
			throw std::exception();
		}
		else
		{
			pList[CurrList].erase(pCurr);
			dataCount--;
		}
	}
	void Reset()
	{
		CurrList = 0;
		pCurr = pList[CurrList].begin();
		while (pCurr == pList[CurrList].end())
		{
			CurrList++;
			if (CurrList < size) 
			{ 
			 pCurr = pList[CurrList].begin();
			}
			else
			{
				break;
			}
		}
	}
	void GoNext()
	{
		pCurr++;
		while (pCurr == pList[CurrList].end())
		{
			CurrList++;
			if (CurrList < size)
			{
				pCurr = pList[CurrList].begin();
			}
			else
			{
				break;
			}
		}
	}
	bool IsEnd()
	{
		return CurrList == size-1;
	}
};

