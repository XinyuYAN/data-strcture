#include <iostream>
using namespace std;
//����ʽ��ӣ�������ʵ��
class Polynomal
{
public:
	Polynomal();//���캯��
	~Polynomal();//��������
	void input();//�������ʽ����
	void display();//�������ʽ
	Polynomal& add(const Polynomal& s);//����ʽ�ӷ�
private:
	struct element{
	float num;//ϵ��
	int exp;//ָ��
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
	cout << "�������" << i <<"������ʽ��ϵ��,��-0.1��������" << endl;
	cin >> temp;
	p->num = temp;
	if(temp == -0.1 )
		break;
	cout << "�������" << i << "������ʽ��ָ��" << endl;
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
