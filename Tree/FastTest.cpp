#include<iostream>
#include<string>
#include<iomanip>
#include "TSortTable.h"
#include "TArrayHash.h"


int main()
{
	TArrayHash hash_tab(10, 3);
	TSortTable st(3);
	TScanTable sct(5);
	TSortTable st1(4);
		TRecord r2(2, "aaaaa");
		sct.Insert(r2);
		TRecord r1(1, "bbbb");
		sct.Insert(r1);
		TRecord r3(3, "cccc");
		sct.Insert(r3);

		TRecord r4(4, "iiii");
		st1.Insert(r1); st1.Insert(r2); st1.Insert(r3); st1.Insert(r4);
		std::cout << "sct before" << std::endl << st1;

		st.ScanToSort(sct, Quick);
		//TSortTable st1(st);
		st1 = st;

	std::cout <<"sct" << std::endl << sct;
	
	std::cout << "st1 after"<<std::endl << st1;
	
	
}