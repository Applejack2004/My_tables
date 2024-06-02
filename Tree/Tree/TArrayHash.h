#pragma once
#include "THashTable.h"
class TArrayHash:public THashTable
{
protected:
	TRecord* pRecs;
	TRecord Empty, Del;
	int Curr_pos, step,Free_pos,size;
public:

	TArrayHash(int _size=MAX_SIZE, int _step = 3)
	{
		if (_size > MAX_SIZE)
		{
			throw std::exception();
		}
		size = _size;
		step = _step;
		pRecs = new TRecord[size];
		Empty.key = -1;
		Del.key = -2;
		Curr_pos = -1;
		for (int i = 0; i < size; i++)
		{
			pRecs[i] = Empty;
		}
		dataCount = 0;
	}

	TArrayHash& operator =(const TArrayHash& other)
	{
		delete[] pRecs;
		size = other.size;
		step = other.step;
		pRecs = new TRecord[size];
		Empty.key = other.Empty.key;
		Del.key = other.Del.key;
		Curr_pos = other.Curr_pos;
		for (int i = 0; i < size; i++)
		{
			pRecs[i] = Empty;
		}
		dataCount =other.dataCount;
		return *this;
	}
	~TArrayHash()
	{
		delete[] pRecs;
		Empty.key = -1;
		Del.key = -2;
		Curr_pos = -1;
		dataCount = 0;
	}

	void Reset()
	{
		for (Curr_pos = 0; Curr_pos < size; Curr_pos++)
		{
			if (pRecs[Curr_pos] != Empty && pRecs[Curr_pos] != Del)
				break;
		}
	}
	bool IsEnd()
	{
		return Curr_pos == size-1;
	}
	void GoNext()
	{
		for (Curr_pos++; Curr_pos < size; Curr_pos++)
		{
			if (pRecs[Curr_pos] != Empty && pRecs[Curr_pos] != Del)
				break;
		}

	}

	bool Find(TKey key)
	{
		//Free_pos = -1;
		Curr_pos = HashFunc(key) % size;
		for (int t = 0; t < size; t++)
		{
			efficiency++;
			if (pRecs[Curr_pos].key == key)
			{
				return true;
			}
			if (pRecs[Curr_pos] == Del && Free_pos == -1)
			{
				Free_pos = Curr_pos;
			}
			if (pRecs[Curr_pos] == Empty)
			{
				Free_pos = Curr_pos;
				return false;
			}
			Curr_pos = (Curr_pos + step) % size;
	
		}
		return false;

	}
	bool IsFull() const 
	{
		if (dataCount == size)
			return true;
		else
		{
			return false;
		}
	} ;

	bool Insert( TRecord rec)
	{
		if (IsFull()) { throw std::exception(); }
		bool isfind = Find(rec.key);
		if (isfind) { return false; }
		else
		{
			if (Free_pos != -1)
			{
				Curr_pos = Free_pos;
			}
			pRecs[Curr_pos] = rec;
			dataCount++;
			efficiency++;
		}
		return true;
	}
	bool Delete(TKey key)
	{
		if (this->IsEmpty())
		{
			throw std::exception();
		}

		bool isfind = Find(key);
		if (!isfind) { return false; }
		else
		{
			pRecs[Curr_pos] = Del;
			dataCount--;
		}
		return true;
	}

	virtual int GetCurrentPos() { return Curr_pos; }
	virtual void SetCurrentPos(int _curPos)
	{
		if (_curPos < size)
		{
			Curr_pos = _curPos;
		}
		else {
			throw std::exception();
		}
	}
	TRecord GetCurrentRecord()  {
		if (Curr_pos<0 && Curr_pos>size)
		{
			throw std::exception();
		}
		return pRecs[Curr_pos];
	}
	void SetCurrentRecord(TRecord record)  
	{
		if (Curr_pos<0 && Curr_pos>size)
		{
			throw std::exception();
		}
		pRecs[Curr_pos] = record; 
	}
	int GetSize() { return size; }
};

