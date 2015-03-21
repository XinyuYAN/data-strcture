#include <iostream>
using namespace std;

class Polynomal
{
public:
	Polynomal();//���캯��
	~Polynomal();//��������
	void input();//�������ʽ����
	void display();//�������ʽ
	Polynomal& add(const Polynomal& a,const Polynomal& b);//����ʽ�ӷ�
private:
	struct element{
	float num;//ϵ��
	int exp;//ָ��
	bool alr;//�ж��Ƿ��������ı�־
	element* next;
	};
	element *first;
};
Polynomal::Polynomal(){
			element* temp=new element;
			temp->next = NULL;
			first=temp;//firstָ��̬����������ͷ���
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
	cout << "�������" << i <<"������ʽ��ϵ��,��-1��������" << endl;
	cin >> temp;
	p->num = temp;
	if(temp == -1 )
		break;
	cout << "�������" << i << "������ʽ��ָ��" << endl;
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

Polynomal& Polynomal::add(const Polynomal& a,const Polynomal& b)//����ʽ�ӷ�
{
	element* ta,*tb;
	for(ta=a.first->next;ta!=NULL;ta=ta->next)
		{
			element *p=new element;
			for(tb=b.first->next;tb!=NULL;tb=tb->next)
			{
				if(ta->exp == tb->exp)//˵���������
				{
					p->num=ta->num+tb->num;//ϵ�����
					p->exp=ta->exp;
					ta->alr=tb->alr=false;
					break;
				}//���������
			}
			if(tb == NULL)//˵���ҵ����û���ҵ�
				{
					p->num=ta->num;
					p->exp=ta->exp;
					ta->alr=false;
				}//����Ԫ����ӽ�c��
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
		if(tb->alr)//˵��b������ʣ��Ԫ��
		{
			element *p=new element;
			p->num=tb->num;
			p->exp=tb->exp;
			tb->alr=false;
			p->next=this->first->next;
			this->first->next=p;
		}//ȫ��ֱ����ӽ�c��
	}
	return *this;
}
