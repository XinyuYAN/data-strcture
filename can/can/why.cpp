#include <iostream>
#include "plus.h"
using namespace std;
//����ʽ��ӣ�������ʵ��

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
