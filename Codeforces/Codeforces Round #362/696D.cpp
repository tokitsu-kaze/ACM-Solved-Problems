#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=200+10;
const ll mod=1e9+7;
const int sz=201;
struct Matrix
{
	ll c[sz][sz],n;
	Matrix(){}
	Matrix(ll a,ll v=0)
	{
		int i,j;
		n=a;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=v;
			}
		}
	}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n,-INF);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					res.c[i][j]=max(res.c[i][j],c[i][k]+b.c[k][j]);
				}
			}
		}
		return res;
	}
};
Matrix matpow2(Matrix a,ll b)
{
	Matrix res(a.n,-INF);
	for(int i=0;i<a.n;i++)
	{
		res.c[i][i]=0;
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
	int next[MAX][26],fail[MAX],cnt[MAX];
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
	void insert(char *s,int v)
	{
		int len,now,i;
		len=strlen(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=s[i]-'a';
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
		}
		cnt[now]+=v;
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<26;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			cnt[now]+=cnt[fail[now]];
			for(i=0;i<26;i++)
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
		Matrix res(tot,-INF);
		int i,j;
		for(i=0;i<tot;i++)
		{
			for(j=0;j<26;j++)
			{
				res.c[i][next[i][j]]=max(res.c[i][next[i][j]],(ll)cnt[next[i][j]]);
			}
		}
		res=matpow2(res,k);
		ll ans=0;
		for(i=0;i<tot;i++)
		{
			ans=max(ans,res.c[0][i]);
		}
		printf("%lld\n",ans);
	}
}acm;
int v[MAX];
int main()
{
	int n,i,j;
	ll k;
	char s[222];
	while(~scanf("%d%lld",&n,&k))
	{
		acm.init();
		for(i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		for(i=0;i<n;i++) 
		{
			scanf("%s",s);
			acm.insert(s,v[i]);
		}
		acm.setfail();
		acm.solve(k);
	}
	return 0;
}