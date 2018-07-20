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
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e6;
struct Trie
{
	Trie *p[2];
	int h,s;
	Trie()
	{
		s=0;
		p[0]=p[1]=NULL;
	}
	void calsum()
	{
		s=0;
		if(p[0]!=NULL) s+=p[0]->s;
		if(p[1]!=NULL) s+=p[1]->s;
	}
}*root;
int temp[28];
void init()
{
	int i,j;
	for(i=1,j=27;i<=1e8;i*=2,j--)
	{
		temp[j]=i;
//		cout<<j<<" "<<temp[j]<<endl;
	}
}
void change(int x,int *res)
{
	int i;
	for(i=1;i<=27;i++)
	{
		if(temp[i]<=x)
		{
			res[i]=1;
			x-=temp[i];
		}
		else res[i]=0;
//		cout<<res[i];
	}
}
void Insert(Trie *&p,int *v,int h)
{
	if(p==NULL)
	{
		p=new Trie;
		p->h=h;
	}
	if(h==27)
	{
		p->s++;
		return;
	}
	if(v[h+1]==0) Insert(p->p[0],v,h+1);
	else Insert(p->p[1],v,h+1);
	p->calsum();
}
void Delete(Trie *&p,int *v,int h)
{
	if(h==27)
	{
		p->s--;
		return;
	}
	if(v[h+1]==0) Delete(p->p[0],v,h+1);
	else Delete(p->p[1],v,h+1);
	p->calsum();
}
int query(Trie *p,int *a,int *b,int h)
{
	if(b[h+1]==0)
	{
		if(a[h+1]==1)
		{
			if(p->p[1]!=NULL)
			{
				if(h==26) return 0;
				else return query(p->p[1],a,b,h+1);
			}
			else return 0;
		}
		else
		{
			if(p->p[0]!=NULL)
			{
				if(h==26) return 0;
				else return query(p->p[0],a,b,h+1);
			}
			else return 0;
		}
	}
	else if(b[h+1]==1)
	{
		if(h==26)
		{
			if(a[h+1]==1)
			{
				if(p->p[1]==NULL) return 0;
				else return p->p[1]->s;
			}
			else
			{
				
				if(p->p[0]==NULL) return 0;
				else return p->p[0]->s;
			}
		}
		else
		{
			int temp=0;
			if(a[h+1]==1)
			{
				if(p->p[0]!=NULL) temp=query(p->p[0],a,b,h+1);
				if(p->p[1]==NULL) return temp;
				else return p->p[1]->s+temp;
			}
			else if(a[h+1]==0)
			{
				if(p->p[1]!=NULL) temp=query(p->p[1],a,b,h+1);
				if(p->p[0]==NULL) return temp;
				else return p->p[0]->s+temp;
			}
		}
	}
}
int main()
{
	int q,op,x,y,resx[33],resy[33];
	init();
//	change(6,resx);
	while(~scanf("%d",&q))
	{
		root=new Trie;
		while(q--)
		{
			scanf("%d",&op);
			scanf("%d",&x);
			change(x,resx);
			if(op==1) Insert(root,resx,0);
			else if(op==2) Delete(root,resx,0);
			else if(op==3)
			{
				scanf("%d",&y);
				change(y,resy);
				printf("%d\n",query(root,resx,resy,0));
			}
		}
	}
	return 0;
}
/*
4
1 2
3 5 7
1 1
3 5 7
*/