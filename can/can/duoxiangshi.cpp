#include <iostream>
using namespace std;
//多项式相加，用链表实现
class Polynomal
{
public:
	Polynomal();//构造函数
	~Polynomal();//析构函数
	void input();//输入多项式函数
	void display();//输出多项式
	Polynomal& add(const Polynomal& s);//多项式加法
private:
	struct element{
	float num;//系数
	int exp;//指数
	element* next;
	};
	element *first;
};
Polynomal::Polynomal(){
			element* temp=new element;
			temp->next = NULL;
			first=temp;//first指向动态创建出来的头结点
		  }
Polynomal::~Polynomal(){
	for(element *temp=first;first !=NULL;)
	{
		temp=first;
		first=first->next;
		delete temp;
	}
}
void Polynomal ::input()
{
	int i=1,texp;
	float temp=0;
	do{
	element* p = new element;
	cout << "请输入第" << i <<"个多项式的系数,以-0.1结束输入" << endl;
	cin >> temp;
	p->num = temp;
	if(temp == -0.1 )
		break;
	cout << "请输入第" << i << "个多项式的指数" << endl;
	cin >> texp;
	p->exp=texp;
	p->next=this->first->next;
	this->first->next=p;
	}
	while(temp != -0.1);
}
void Polynomal::display()
{
	for(element* temp=this->first->next;temp!=NULL;temp=temp->next)
	{
		if(temp->num <=0)
		{cout << "-";}
		else cout << "+";
		cout << temp->num<<"*" << "x" << "^"<<temp->exp;
	}
	cout << endl;
}
int main()
{
	Polynomal a;
	a.input();
	a.display();
}
