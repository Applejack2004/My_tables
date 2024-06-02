#pragma once
#include "TScanTable.h"

enum SortType{Merge,Bubble,Quick};

class TSortTable:public TScanTable
{
private:
	void BubbleSort();                        //Сортировка пузырьком
	void QuickSort(int first, int last);      //Быстрая сортировка
	void MergeSort(int left, int right);      //Сортировка слиянием
	void Merge( int left,int mid, int right); //Функция объединения 2 частей массива

public: 
	TSortTable(int _size=MAX_SIZE) :TScanTable(_size) {};
	void ScanToSort(TScanTable& table, SortType sortType); //Преобразование типа

	bool Find(TKey key);
	bool Insert(TRecord record);
	bool Delete(TKey key);

	TSortTable operator=(const TSortTable& other)
	{
		if (this->size != other.size)
		{
			delete[] this->arr;
			this->size = other.size;
			this->arr = new TRecord[this->size];
		}
		this->dataCount = other.dataCount;
		this->efficiency = other.efficiency;
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = other.arr[i];
		}
		this->currentPos = other.currentPos;
		return *this;
	}
};

//Реализация
inline void TSortTable::QuickSort(int first, int last)
{
	if (this->IsEmpty()) return;

	int mid = (first + last) / 2;
	TKey key = this->arr[mid].key;
	int leftPos = first, rightPos = last;

	while (leftPos < rightPos)
	{
		while (this->arr[leftPos].key < key)
		{
			leftPos++;
			this->efficiency++;
		}
		while (this->arr[rightPos].key > key)
		{
			rightPos--;
			this->efficiency++;
		}
		if (leftPos <= rightPos)
		{
			std::swap(this->arr[leftPos], this->arr[rightPos]);
			leftPos++; 
			rightPos--; 
			this->efficiency++;
		}
	}

	if (rightPos > first) QuickSort(first, rightPos);
	if (leftPos < last) QuickSort(leftPos, last);
}

inline void TSortTable::BubbleSort()
{
	if (this->IsEmpty()) return;

	for (int i = 0; i < this->dataCount; i++)
	{
		for (int j = i + 1; j < this->dataCount; j++)
		{
			if (this->arr[i].key > this->arr[j].key)
			{
				std::swap(this->arr[i], this->arr[j]);
			}
		}
	}
}

inline void TSortTable::MergeSort(int left, int right)
{
	if (left == right)
	{
		return;
	}
	else
	{
		int mid = (right + left) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		Merge(left, mid, right); 
	}
}

inline void TSortTable::Merge(int left, int mid, int right)
{
	TRecord* mas2;
	mas2 = new TRecord[this->dataCount];
	
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (this->arr[i].key < this->arr[j].key)
		{
			mas2[k] = this->arr[i];
			k++; i++;
		}
		else
		{
			mas2[k] = this->arr[j];
			k++; j++;
		}
	}

	if (i > mid)
	{
		while (j <= right)
		{
			mas2[k] = this->arr[j];
			j++; k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			mas2[k] = this->arr[i];
			i++; k++;
		}
	}

	for (i = left; i <= right; i++)
	{
		this->arr[i] = mas2[i];
	}
	delete[] mas2;
}

inline void TSortTable::ScanToSort(TScanTable& table, SortType sortType)
{
	for (this->Reset(), table.Reset(); !table.IsEnd(); table.GoNext(), this->GoNext())
	{
		this->SetCurrentRecord(table.GetCurrentRecord());
		this->dataCount++;
	}
	if (sortType == SortType::Quick) this->QuickSort(0, this->dataCount - 1);
	if (sortType == SortType::Merge) this->MergeSort(0, this->dataCount - 1);
	if (sortType == SortType::Bubble) this->BubbleSort();
}

inline bool TSortTable::Find(TKey key)
{
	int begin = 0, end = this->dataCount - 1, middle;
	while (begin <= end)
	{
		efficiency++;
		middle = (begin + end) / 2;
		if (this->arr[middle].key < key)
		{
			begin = middle + 1;
		}
		else if (this->arr[middle].key > key)
		{
			end = middle - 1;
		}
		else { 
			this->currentPos = middle; return true; 
		}
	}
	this->currentPos = begin;
	return false;
}

inline bool TSortTable::Insert(TRecord record)
{
	if (IsFull() || Find(record.key))
	{
		return false;
	}
	for (int i = this->dataCount - 1; i >= this->currentPos; i--)
	{
		this->arr[i + 1] = this->arr[i];
		efficiency++;
	}

	this->arr[currentPos] = record;
	efficiency++;
	this->dataCount++;
	return true;
}

inline bool TSortTable::Delete(TKey key)
{
	if (!Find(key))
	{
		return false;
	}
	for (int i = this->currentPos; i < this->dataCount - 1; i++)
	{
		this->arr[i] = this->arr[i + 1];
		efficiency++;
	}
	this->dataCount--;
	return true;
}
