#include<iostream>
#include<string>
#include<iomanip>
#include "TSortTable.h"
#include "TTreeTable.h"


int main()
{
	TTreeTable tree;

	TRecord rec4(4, "test4");
	tree.Insert(rec4);

	TRecord rec3(3, "test3");
	tree.Insert(rec3);

	TRecord rec2(2, "test2");
	tree.Insert(rec2);

	TRecord rec5(5, "test5");
	tree.Insert(rec5);

	TRecord rec6(6, "test6");
	tree.Insert(rec6);

	TRecord rec7(7, "test7");
	tree.Insert(rec7);
	tree.Reset();

	TRecord rec1(1, "test7");
	tree.Insert(rec1);
	tree.Reset();

	std::cout<<tree.GetCurrentRecord().key;
	std::cout << tree;
	//std::cout <<"sct" << std::endl << sct;
	
	//std::cout << "st1 after"<<std::endl << st1;
	
	
}