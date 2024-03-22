#include<iostream>
#include<string>
#include<iomanip>
#include "TSortTable.h"


int main()
{
	
	TSortTable st(3);
	TScanTable sct(5);
	for (int i = 1; i <= sct.GetSize(); i++)
	{
		TRecord r(i, "aaaaa");
		sct.Insert(r);
	}
	

	st.ToSort(sct,Quick);
	for (st.Reset();!st.IsEnd();st.GoNext())
	{
		st.GetCurrentRecord().output();
	}
	//std::cout << st;
}