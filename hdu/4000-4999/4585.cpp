////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-02 22:17:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4585
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:6984KB
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
struct Treap
{
	int v,id;
	int w,size,fix;
	Treap *l,*r;
	Treap()
	{
		w=size=1;
		l=r=NULL;
		fix=rand();
	}
	void calsize()
	{
		size=(l==NULL?0:l->size)+(r==NULL?0:r->size)+w;
	}
}*root;
Treap *LRotate(Treap *p)
{
	Treap *q;
	q=p->r;
	p->r=q->l;
	q->l=p;
	q->size=p->size;
	p->calsize();
	return q;
}
Treap *RRotate(Treap *p)
{
	Treap *q;
	q=p->l;
	p->l=q->r;
	q->r=p;
	q->size=p->size;
	p->calsize();
	return q;
}
Treap *Insert(Treap *p,int id,int v)
{
	if(p==NULL)
	{
		p=new Treap;
		p->v=v;
		p->id=id;
		return p;
	}
	if(v==p->v) p->w++;
	else if(v<p->v)
	{
		p->l=Insert(p->l,id,v);
		if(p->l!=NULL&&p->l->fix<p->fix) p=RRotate(p);
	}
	else if(v>p->v)
	{
		p->r=Insert(p->r,id,v);
		if(p->r!=NULL&&p->r->fix<p->fix) p=LRotate(p);
	}
	p->calsize();
	return p;
}
Treap *Delete(Treap *p,int v)
{
	if(p==NULL) return NULL;
	if(v<p->v) p->l=Delete(p->l,v);
	else if(v>p->v) p->r=Delete(p->r,v);
	else
	{
		if(p->w>1) p->w--;
		else if(p->l==NULL&&p->r==NULL)
		{
			delete p;
			return NULL;
		}
		else
		{
			if(p->l!=NULL&&p->r!=NULL&&p->l->fix<p->r->fix) p=LRotate(p);
			else if(p->r!=NULL) p=LRotate(p);
			else p=RRotate(p);
			p=Delete(p,v);
		}
	}
	p->calsize();
	return p;
}
int FindPre(Treap *p,int v)
{
	if(p==NULL) return -int(1e9+10);
	if(v<p->v) return FindPre(p->l,v);
	else if(v==p->v) return v;
	else return max(p->v,FindPre(p->r,v));
}
int FindSuc(Treap *p,int v)
{
	if(p==NULL) return int(1e9+10);
	if(v>p->v) return FindSuc(p->r,v);
	else if(v==p->v) return v;
	else return min(p->v,FindSuc(p->l,v));
}
int Find(Treap *p,int v)
{
	if(p!=NULL)
	{
		if(p->v==v) return p->id;
		else if(v<p->v) return Find(p->l,v);
		else if(v>p->v) return Find(p->r,v);
	}
}
int FindRank(Treap *p,int v,int s)//从小到大 
{
	int t=p->l==NULL?0:p->l->size;  
	if(v==p->v) return t+s+1;  
	else if(v<p->v) return FindRank(p->l,v,s);  
	else return FindRank(p->r,v,t+s+p->w);  
}
int FindKthMax(Treap *p,int k)
{
	if(p==NULL||k<0||k>p->size) return 0;
	int t=p->l==NULL?0:p->l->size;
	if(k==t+1) return p->v;
	else if(k<=t) return FindKthMax(p->l,k);
	else return FindKthMax(p->r,k-t-p->w);
}
int main()
{
	int n,id,v,a,b;
	while(~scanf("%d",&n)&&n)
	{
		root=new Treap;
		root->id=1;
		root->v=1000000000;
		while(n--)
		{
			scanf("%d%d",&id,&v);
			a=FindPre(root,v);
			b=FindSuc(root,v);
			root=Insert(root,id,v);
			if(abs(a-v)<=abs(b-v)) printf("%d %d\n",id,Find(root,a));
			else printf("%d %d\n",id,Find(root,b));
		}
	}
	return 0;
}
/*
4
2 1
3 7
4 4
5 6
*/