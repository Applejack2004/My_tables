#pragma once
#include"TArrayTable.h"

class TScanTable:public TArrayTable
{
public:
	TScanTable(int _size = 10) : TArrayTable(_size) {};

	bool Find(TKey key) override;
	bool Insert(TRecord record) override;
	bool Delete(TKey key) override;
};

//Реализация
inline bool TScanTable::Find(TKey key)
{
	for (int i = 0; i < dataCount; i++)
	{
		efficiency++;
		if (arr[i].key == key)
		{
			currentPos = i;
			return true;
		}
	}
	currentPos = dataCount;
	return false;
}

inline bool TScanTable::Insert(TRecord record)
{
	if (IsFull() || Find(record.key)) return false;
	arr[dataCount+1] = record;
	efficiency++;
	return true;
}

inline bool TScanTable::Delete(TKey key)
{
	if (!Find(key)) return false;
	arr[currentPos] = arr[dataCount - 1];
	dataCount--;
	efficiency++;
	return true;
}

