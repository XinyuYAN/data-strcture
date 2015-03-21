#include <iostream>
#include "plus.h"
using namespace std;
//多项式相加，用链表实现

int main()
{
	Polynomal a;
	a.input();
	a.display();
	Polynomal b;
	b.input();
	b.display();
	Polynomal c;
	c.add(a,b);
	c.display();
	return 0;
}
