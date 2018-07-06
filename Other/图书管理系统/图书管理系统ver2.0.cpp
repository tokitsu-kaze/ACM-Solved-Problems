#include <bits/stdc++.h>
#include <windows.h>
#include "LIST.h"
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
void CoverColor(int n)
{
	HANDLE hdl=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hdl,n);
}
void add()
{
	int op;
	puts("��ѡ�����:");
	puts("0.������һ���˵� 1.���ͼ��");
	scanf("%d",&op);
	if(!op) return;
	puts("��������� ���� ��� ���������Ϊ-1��ʾ��ӽ�����"); 
	DataAdd();
	CoverColor(252);
	puts("��ӳɹ�!");
	CoverColor(7);
}
void del()
{
	int op;
	puts("��ѡ�����:");
	puts("0.������һ���˵� 1.�������ɾ�� 2.��������ɾ��");
	scanf("%d",&op);
	if(!op) return;
	int flag=DataDel(op);
	CoverColor(252);
	if(flag) puts("ɾ���ɹ�!");
	else puts("û�и���...");
	CoverColor(7);
}

void mysort()
{
	int op;
	puts("��ѡ�����:");
	puts("0.������һ���˵� 1.����������� 2.������Ž��� 3.���ݲ��������� 4.���ݲ���������");
	scanf("%d",&op);
	if(!op) return;
	ListSort(op);
	CoverColor(252);
	puts("����ɹ�!");
	CoverColor(7);
}
void find()
{
	int op,id;
	linklist *res;
	char name[1111];
	puts("��ѡ�����:");
	puts("0.������һ���˵� 1.������Ų��� 2.������������");
	scanf("%d",&op);
	if(!op) return;
	res=NULL;
	if(op==1)
	{
		puts("���������");
		scanf("%d",&id);
		res=findid(id);
	}
	else if(op==2)
	{
		puts("����������");
		mem(name,0);
		scanf("%s",name);
		res=findname(name);
	}
	CoverColor(252);
	if(res==NULL) puts("û�и���...");
	else
	{
		puts("���ҳɹ�!");
		printf("%d %s %s %d %d\n",res->data.n,res->data.name,res->data.kind,res->data.sum,res->data.now);
	}
	CoverColor(7);
}
void bookoperator(int tag)
{
	int op,id;
	linklist *res;
	char name[1111];
	puts("��ѡ�����:");
	puts("0.������һ���˵� 1.������Ų��� 2.������������");
	scanf("%d",&op);
	if(!op) return;
	res=NULL;
	if(op==1)
	{
		puts("���������");
		scanf("%d",&id);
		res=findid(id);
	}
	else if(op==2)
	{
		puts("����������");
		mem(name,0);
		scanf("%s",name);
		res=findname(name);
	}
	CoverColor(252);
	if(res==NULL) puts("û�и���...");
	else
	{
		if(tag==5)
		{
			if(res->data.now==0) puts("�ѽ���...");
			else
			{
				res->data.now--;
				puts("����ɹ�!");
			}
		}
		else if(tag==6)
		{
			res->data.now++;
			puts("����ɹ�!");
		}
	}
	CoverColor(7);
}
int main()
{
	int op,t;
//	freopen("in.txt","r",stdin);
	head=tail=new linklist;
	while(1)
	{
		puts("��ѡ�����:");
		puts("0.�˳� 1.��� 2.ɾ�� 3.���� 4.���� 5.���� 6.����");
		scanf("%d",&op);
		switch(op)
		{
			case 0:return 0;break;
			case 1:add();break;
			case 2:del();break;
			case 3:mysort();break;
			case 4:find();break;
			case 5:bookoperator(op);break;
			case 6:bookoperator(op);break;
		}
//		debug();
		puts("");
	}
}
