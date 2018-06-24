////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-05 18:52:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4825
////Problem Title: 
////Run result: Accept
////Run time:748MS
////Run memory:84392KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct Trie
{
	Trie *p[2];
	ll h,s;
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
ll temp[44];
void init()
{
	ll i,j;
	for(i=1,j=34;i<=1e10;i*=2,j--)
	{
		temp[j]=i;
	}
}
void change(ll x,ll *res)
{
	ll i;
	for(i=1;i<=34;i++)
	{
		if(temp[i]<=x)
		{
			res[i]=1;
			x-=temp[i];
		}
		else res[i]=0;
	}
}
void Insert(Trie *&p,ll *v,ll h)
{
	if(p==NULL)
	{
		p=new Trie;
		p->h=h;
	}
	if(h==34)
	{
		p->s++;
		return;
	}
	if(v[h+1]==0) Insert(p->p[0],v,h+1);
	else Insert(p->p[1],v,h+1);
	p->calsum();
}
void query(Trie *&p,ll *v,ll *ans,ll h)
{
	if(h==34) return;
	if(v[h+1]==0)
	{
		if(p->p[1]!=NULL)
		{
			ans[h+1]=1;
			query(p->p[1],v,ans,h+1);
		}
		else if(p->p[0]!=NULL) query(p->p[0],v,ans,h+1);
		else return;
	}
	else if(v[h+1]==1)
	{
		if(p->p[0]!=NULL) query(p->p[0],v,ans,h+1);
		else if(p->p[1]!=NULL)
		{
			ans[h+1]=1;
			query(p->p[1],v,ans,h+1);
		}
		else return;
	}
}
int main()
{
	ll t,cas=1,n,m,x,i,res[44],ans[44];
	init();
	scanf("%lld",&t);
	while(t--)
	{
		root=new Trie;
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			change(x,res);
			Insert(root,res,0);
		}
		printf("Case #%lld:\n",cas++);
		while(m--)
		{
			scanf("%lld",&x);
			change(x,res);
			mem(ans,0);
			query(root,res,ans,0);
			ll y=0;
			for(i=34;i>=1;i--)
			{
				if(ans[i]) y+=temp[i];
			}
			printf("%lld\n",y);
		}
	}
	return 0;
}
/*
2
2 2
3 1000000000
1
888

*/