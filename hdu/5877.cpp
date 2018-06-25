////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-06 13:02:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5877
////Problem Title: 
////Run result: Accept
////Run time:1154MS
////Run memory:22472KB
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
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=1e5+10;
ll a[MAX],pre[MAX],rt,ans,k;
vector<ll> mp[MAX];
struct Treap
{
	ll v;
	ll w,size,fix;
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
void LRotate(Treap *&p)
{
	Treap *q;
	q=p->r;
	p->r=q->l;
	q->l=p;
	q->size=p->size;
	p->calsize();
	p=q;
}
void RRotate(Treap *&p)
{
	Treap *q;
	q=p->l;
	p->l=q->r;
	q->r=p;
	q->size=p->size;
	p->calsize();
	p=q;
}
void Insert(Treap *&p,ll v)
{
	if(p==NULL)
	{
		p=new Treap;
		p->v=v;
		return ;
	}
	else
	{
		if(v==p->v) p->w++;
		else if(v<p->v)
		{
			Insert(p->l,v);
			if(p->l!=NULL&&p->l->fix<p->fix) RRotate(p);
		}
		else if(v>p->v)
		{
			Insert(p->r,v);
			if(p->r!=NULL&&p->r->fix<p->fix) LRotate(p);
		}
	}
	p->calsize();
}
void Delete(Treap *&p,ll v)
{
	if(p==NULL) return;
	if(v<p->v) Delete(p->l,v);
	else if(v>p->v) Delete(p->r,v);
	else
	{
		if(p->w>1) p->w--;
		else if(p->l!=NULL&&p->r!=NULL)
		{
			if(p->l->fix<p->r->fix) LRotate(p);
			else RRotate(p);
			Delete(p,v);
		}
		else
		{
			Treap *q=p;
			if(p->l==NULL) p=p->r;
			else p=p->l;
			delete q;
			return;
		}
	}
	p->calsize();
}
ll Find(Treap *p,ll v)
{
	if(p==NULL) return 0;
	ll temp=(p->l==NULL?0:p->l->size);
	if(v>=p->v) return temp+p->w+Find(p->r,v);
	else return Find(p->l,v);
}
void dfs(ll rt)
{
	ll i;
	ans+=Find(root,a[rt]==0?1e11:k/a[rt]);
	Insert(root,a[rt]);
	for(i=0;i<mp[rt].size();i++)
	{
		dfs(mp[rt][i]);
	}
	Delete(root,a[rt]);
}
int main()
{
	ll t,n,i,u,v;
	scanf("%lld",&t);
	while(t--)
	{
		root=NULL;
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			pre[i]=i;
			mp[i].clear();
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%lld%lld",&u,&v);
			pre[v]=u;
			mp[u].pb(v);
		}
		for(i=1;i<=n;i++)
		{
			if(pre[i]==i)
			{
				rt=i;
				break;
			}
		}
	//	cout<<rt<<endl;
		ans=0;
		dfs(rt);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
2
3 444
1 1 1
2 1
1 3
*/