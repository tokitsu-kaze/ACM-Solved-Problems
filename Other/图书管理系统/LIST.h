#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
struct data
{
	int n,sum,now;
	char name[1111],kind[1111];
}data;
struct linklist
{
	struct data data;
	linklist *next;
	linklist()
	{
		data.n=-1;
		data.now=data.sum=0;
		mem(data.name,0);
		mem(data.kind,0);
		next=NULL;
	}
}*head,*tail;
linklist *findid(int key)
{
	linklist *p;
	for(p=head;p->next!=NULL;p=p->next)
	{
		if(p->data.n==key) return p;
	}
}
linklist *findname(char key[])
{
	linklist *p;
	for(p=head;p->next!=NULL;p=p->next)
	{
		if(strcmp(p->data.name,key)==0) return p;
	}
}
void ListSort(int op)
{
	linklist *p,*q,*t,*temp;
	temp=new linklist;
	for(p=head;p->next!=NULL;p=p->next)
	{
		t=p;
		for(q=p->next;q->next!=NULL;q=q->next)
		{
			if((op==1&&q->data.n<t->data.n)||(op==3&&q->data.now<t->data.now)) t=q;
			else if((op==2&&q->data.n>t->data.n)||(op==4&&q->data.now>t->data.now)) t=q;
		}
		if(t!=p)
		{
			temp->data=p->data;
			p->data=t->data;
			t->data=temp->data;
		}
	}
}
void DataAdd()
{
	linklist *q,*res;
	res=NULL;
	while(scanf("%d",&data.n)&&data.n!=-1)
	{
		getchar();
		scanf("%s %s %d",data.name,data.kind,&data.sum);
		res=findid(data.n);
		if(res!=NULL)
		{
			res->data.sum+=data.sum;
			res->data.now+=data.sum;
		}
		else
		{
			data.now=data.sum;
			tail->data=data;
			q=new linklist;
			tail->next=q;
			tail=q;
		}
	}
} 
int DataDel(int op)
{
	int id;
	char name[1111];
	linklist *p,*q;
	if(op==1)
	{
		puts("请输入书号");
		scanf("%d",&id);
	}
	else if(op==2)
	{
		puts("请输入书名");
		mem(name,0);
		scanf("%s",name);
	}
	for(p=head;p->next!=NULL;p=p->next)
	{
		if((op==1&&p->data.n==id)||(op==2&&strcmp(p->data.name,name)==0))
		{
			if(p==head) head=p->next;
			else if(p==tail)
			{
				tail=q;
				tail->next=NULL;
			}
			else q->next=p->next;
			return 1;
		}
		q=p;
	}
	return 0;
}



void debug()
{
	linklist *p;
	puts("");
	puts("***********************************************");
	for(p=head;p->next!=NULL;p=p->next)
	{
		printf("%d %s %s %d %d\n",p->data.n,p->data.name,p->data.kind,p->data.sum,p->data.now);
	}
	puts("***********************************************");
	puts("");
}
