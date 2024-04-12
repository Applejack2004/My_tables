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
		if (_size > MAX_SIZE)
		{
			throw std::exception();
		}
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
		bool isfind = Find(record.key);
		if (isfind) { return false; }
		else 
		{
			pList[CurrList].push_front(record);
			dataCount++;
		}
		return true;
	}
	bool Delete(TKey _key)
	{
		if (this->IsEmpty())
		{
			throw std::exception();
		}

		bool isfind = Find(_key);
		if (!isfind) { return false; }
		else
		{
			pList[CurrList].erase(pCurr);
			dataCount--;
		}
		return true;
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

	int GetSize() { return size; }
	bool IsFull() const
	{
		if (dataCount == size)
			return true;
		else
		{
			return false;
		}
	};
	virtual int GetCurrentPos() { return CurrList; }
	virtual void SetCurrentPos(int _curPos)
	{
		if (_curPos < size)
		{
			CurrList = _curPos;
		}
		else {
			throw std::exception();
		}
	}
	TRecord GetCurrentRecord() 
	{
		return *pCurr;
	}
	void SetCurrentRecord(TRecord record)
	{
		if (CurrList<0 && CurrList>size)
		{
			throw std::exception();
		}
		pList[CurrList].push_front(record);
	
	}
};

