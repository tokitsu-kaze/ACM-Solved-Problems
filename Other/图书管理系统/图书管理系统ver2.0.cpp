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
	puts("请选择操作:");
	puts("0.返回上一级菜单 1.添加图书");
	scanf("%d",&op);
	if(!op) return;
	puts("请输入序号 书名 类别 数量，序号为-1表示添加结束。"); 
	DataAdd();
	CoverColor(252);
	puts("添加成功!");
	CoverColor(7);
}
void del()
{
	int op;
	puts("请选择操作:");
	puts("0.返回上一级菜单 1.根据书号删除 2.根据书名删除");
	scanf("%d",&op);
	if(!op) return;
	int flag=DataDel(op);
	CoverColor(252);
	if(flag) puts("删除成功!");
	else puts("没有该书...");
	CoverColor(7);
}

void mysort()
{
	int op;
	puts("请选择操作:");
	puts("0.返回上一级菜单 1.根据书号升序 2.根据书号降序 3.根据藏书量升序 4.根据藏书量降序");
	scanf("%d",&op);
	if(!op) return;
	ListSort(op);
	CoverColor(252);
	puts("排序成功!");
	CoverColor(7);
}
void find()
{
	int op,id;
	linklist *res;
	char name[1111];
	puts("请选择操作:");
	puts("0.返回上一级菜单 1.根据书号查找 2.根据书名查找");
	scanf("%d",&op);
	if(!op) return;
	res=NULL;
	if(op==1)
	{
		puts("请输入书号");
		scanf("%d",&id);
		res=findid(id);
	}
	else if(op==2)
	{
		puts("请输入书名");
		mem(name,0);
		scanf("%s",name);
		res=findname(name);
	}
	CoverColor(252);
	if(res==NULL) puts("没有该书...");
	else
	{
		puts("查找成功!");
		printf("%d %s %s %d %d\n",res->data.n,res->data.name,res->data.kind,res->data.sum,res->data.now);
	}
	CoverColor(7);
}
void bookoperator(int tag)
{
	int op,id;
	linklist *res;
	char name[1111];
	puts("请选择操作:");
	puts("0.返回上一级菜单 1.根据书号查找 2.根据书名查找");
	scanf("%d",&op);
	if(!op) return;
	res=NULL;
	if(op==1)
	{
		puts("请输入书号");
		scanf("%d",&id);
		res=findid(id);
	}
	else if(op==2)
	{
		puts("请输入书名");
		mem(name,0);
		scanf("%s",name);
		res=findname(name);
	}
	CoverColor(252);
	if(res==NULL) puts("没有该书...");
	else
	{
		if(tag==5)
		{
			if(res->data.now==0) puts("已借完...");
			else
			{
				res->data.now--;
				puts("借书成功!");
			}
		}
		else if(tag==6)
		{
			res->data.now++;
			puts("还书成功!");
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
		puts("请选择操作:");
		puts("0.退出 1.添加 2.删除 3.排序 4.查找 5.借书 6.还书");
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
