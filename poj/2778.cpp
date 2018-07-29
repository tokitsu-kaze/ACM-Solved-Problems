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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100+10;
const ll mod=100000;
const int sz=101;
struct Matrix
{
	ll c[sz][sz],n;
	Matrix(){}
	Matrix(int a)
	{
		n=a;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				c[i][j]=0;
			}
		}
	}
	Matrix operator *(const Matrix &b)const
	{
		Matrix res=Matrix(n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					res.c[i][j]=(res.c[i][j]+c[i][k]*b.c[k][j])%mod;
				}
			}
		}
		return res;
	}
};
int pos[222];
Matrix matpow2(Matrix a,ll b)
{
	Matrix res=Matrix(a.n);
	for(int i=0;i<res.n;i++)
	{
		res.c[i][i]=1;
	}
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
struct ACM
{
	int next[MAX][4],fail[MAX],cnt[MAX];
	int root,tot;
	int newnode()
	{
		int i;
		mem(next[tot],0);
		fail[tot]=0;
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s)
	{
		int len,now,i;
		len=strlen(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=pos[s[i]];
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
		}
		cnt[now]=1;
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<4;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			if(cnt[fail[now]]) cnt[now]=1;
			for(i=0;i<4;i++)
			{
				if(next[now][i])
				{
					fail[next[now][i]]=next[fail[now]][i];
					q.push(next[now][i]);
				}
				else next[now][i]=next[fail[now]][i];
			}
		}
	}
	void solve(ll k)
	{
		Matrix res=Matrix(tot);
		int i,j,ans;
		for(i=0;i<tot;i++)
		{
			for(j=0;j<4;j++)
			{
				res.c[i][next[i][j]]+=(cnt[next[i][j]]^1);
			}
		}
		ans=0;
	/*	for(i=0;i<tot;i++)
		{
			for(j=0;j<tot;j++)
			{
				cout<<res.c[i][j]<<" ";
			}
			puts("");
		}*/
		res=matpow2(res,k);
	/*	for(i=0;i<tot;i++)
		{
			for(j=0;j<tot;j++)
			{
				cout<<res.c[i][j]<<" ";
			}
			puts("");
		}*/
		for(i=0;i<tot;i++)
		{
			ans=(ans+res.c[0][i])%mod;
		}
		printf("%d\n",ans);
	}
}acm;
int main()
{
	int n,i;
	ll k;
	char s[12];
	pos['A']=0;
	pos['T']=1;
	pos['C']=2;
	pos['G']=3;
	while(~scanf("%d%lld",&n,&k))
	{
		acm.init();
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			acm.insert(s);
		}
		acm.setfail();
		acm.solve(k);
	}
	return 0;
}