////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-02 14:49:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1908
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1736KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e9+7;
struct AVLTree
{
	int id,v;
	int h;
	AVLTree *l,*r;
	AVLTree()
	{
		id=v=h=0;
		l=r=NULL;
	}
}*root;
int calH(AVLTree *p)
{
	return p==NULL?0:p->h;
}
AVLTree *LLRote(AVLTree *p)
{
	AVLTree *q;
	q=p->l;
	p->l=q->r;
	q->r=p;
	p->h=max(calH(p->l),calH(p->r))+1;
	q->h=max(calH(q->l),calH(q->r))+1;
	return q;
}
AVLTree *RRRote(AVLTree *p)
{
	AVLTree *q;
	q=p->r;
	p->r=q->l;
	q->l=p;
	p->h=max(calH(p->l),calH(p->r))+1;
	q->h=max(calH(q->l),calH(q->r))+1;
	return q;
}
AVLTree *LRRote(AVLTree *p)
{
	p->l=RRRote(p->l);
	return LLRote(p);
}
AVLTree *RLRote(AVLTree *p)
{
	p->r=LLRote(p->r);
	return RRRote(p);
}
AVLTree *insert(AVLTree *p,int id,int v)
{
	if(p==NULL)
	{
		p=new AVLTree;
		p->id=id;
		p->v=v;
		return p;
	}
	if(v<p->v)
	{
		p->l=insert(p->l,id,v);
		if(calH(p->l)-calH(p->r)==2)
		{
			if(v<p->v) p=LLRote(p);
			else p=LRRote(p);
		}
	}
	else if(v>p->v)
	{
		p->r=insert(p->r,id,v);
		if(calH(p->r)-calH(p->l)==2)
		{
			if(v>p->v) p=RRRote(p);
			else p=RLRote(p);
		}
	}
	p->h=max(calH(p->l),calH(p->r))+1;
	return p;
}
AVLTree *Delete(AVLTree *p,AVLTree *del)
{
	if(p==NULL) return NULL;
	if(del->v<p->v)
	{
		p->l=Delete(p->l,del);
		if(calH(p->r)-calH(p->l)==2)
		{
			AVLTree *temp=p->r;
			if(calH(temp->l)>calH(temp->r)) p=RLRote(p);
			else p=RRRote(p);
		}
	}
	else if(del->v>p->v)
	{
		p->r=Delete(p->r,del);
		if(calH(p->l)-calH(p->r)==2)
		{
			AVLTree *temp=p->l;
			if(calH(temp->r)>calH(temp->l)) p=LRRote(p);
			else p=LLRote(p);
		}
	}
	else if(del->v==p->v)
	{
		if(del->l!=NULL&&del->r!=NULL)
		{
			if(calH(p->l)>calH(p->r))
			{
				AVLTree *temp=p->l;
				while(temp->r!=NULL) temp=temp->r;
				p->v=temp->v;
				p->id=temp->id;
				p->l=Delete(p->l,temp);
			}
			else
			{
				AVLTree *temp=p->r;
				while(temp->l!=NULL) temp=temp->l;
				p->v=temp->v;
				p->id=temp->id;
				p->r=Delete(p->r,temp);
			}
		}
		else
		{
			AVLTree *temp=p;
			p=p->l!=NULL?p->l:p->r;
			delete temp;
		}
	}
	return p;
}
int Findmax(AVLTree *p)
{
	if(p->r==NULL)
	{
		int res=p->id;
		root=Delete(root,p);
		return res;
	}
	return Findmax(p->r);
}
int Findmin(AVLTree *p)
{
	if(p->l==NULL)
	{
		int res=p->id;
		root=Delete(root,p);
		return res;
	}
	return Findmin(p->l);
}
int main()
{
	int op,v,id;
	root=NULL;
	while(~scanf("%d",&op)&&op)
	{
		if(op==1)
		{
			scanf("%d%d",&id,&v);
			root=insert(root,id,v);
		}
		else if(op==2)
		{
			if(root==NULL) puts("0");
			else printf("%d\n",Findmax(root));
		}
		else if(op==3)
		{
			if(root==NULL) puts("0");
			else printf("%d\n",Findmin(root));
		}
	}
	return 0;
}