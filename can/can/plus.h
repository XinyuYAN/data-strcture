#include <iostream>
using namespace std;

class Polynomal
{
public:
	Polynomal();//构造函数
	~Polynomal();//析构函数
	void input();//输入多项式函数
	void display();//输出多项式
	Polynomal& add(const Polynomal& a,const Polynomal& b);//多项式加法
private:
	struct element{
	float num;//系数
	int exp;//指数
	bool alr;//判断是否加入链表的标志
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
	cout << "请输入第" << i <<"个多项式的系数,以-1结束输入" << endl;
	cin >> temp;
	p->num = temp;
	if(temp == -1 )
		break;
	cout << "请输入第" << i << "个多项式的指数" << endl;
	cin >> texp;
	p->exp=texp;
	p->alr=true;
	p->next=this->first->next;
	this->first->next=p;
	i++;
	}
	while(temp != -1);
}
void Polynomal::display()
{
	for(element* temp=this->first->next;temp!=NULL;temp=temp->next)
		if(temp != this->first->next)
			if(temp->num <=0)
				cout <<"+" << "(" << temp->num << ")" <<"*" << "x" << "^"<<temp->exp;
			else 
				cout << "+" << temp->num<<"*" << "x" << "^"<<temp->exp;
		else
			if(temp->num <0)
				 cout << "(" << temp->num << ")" <<"*" << "x" << "^"<<temp->exp;
			else
				cout << temp->num<<"*" << "x" << "^"<<temp->exp;

	cout << endl;
}

Polynomal& Polynomal::add(const Polynomal& a,const Polynomal& b)//多项式加法
{
	element* ta,*tb;
	for(ta=a.first->next;ta!=NULL;ta=ta->next)
		{
			element *p=new element;
			for(tb=b.first->next;tb!=NULL;tb=tb->next)
			{
				if(ta->exp == tb->exp)//说明可以相加
				{
					p->num=ta->num+tb->num;//系数相加
					p->exp=ta->exp;
					ta->alr=tb->alr=false;
					break;
				}//做相加运算
			}
			if(tb == NULL)//说明找到最后都没有找到
				{
					p->num=ta->num;
					p->exp=ta->exp;
					ta->alr=false;
				}//将该元素添加进c中
			if(p->num==0)
				delete p;
			else
			{
				p->next=this->first->next;
				this->first->next=p;
			}
		}
	for(tb=b.first->next;tb != NULL;tb=tb->next)
	{
		if(tb->alr)//说明b中仍有剩余元素
		{
			element *p=new element;
			p->num=tb->num;
			p->exp=tb->exp;
			tb->alr=false;
			p->next=this->first->next;
			this->first->next=p;
		}//全部直接添加进c中
	}
	return *this;
}
