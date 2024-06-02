#include <cstdlib>
#include<time.h>
#include "AVLTree.h"
#include "TTable.h"
#include  <string>

int main()
{
	AVLTree t;
	srand(time(NULL));
	for (int i = 0; i < 400; i++) {
		int r = rand() % 11171;
		TRecord rec(r, std::to_string(rand() % 171));
		t.Insert(rec);
	}
}