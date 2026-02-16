#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x){return qpow(x,mod-2);}
int ord[MAX],id[MAX],fa[MAX],sz[MAX],to[MAX][2];
int a[MAX],l[MAX],r[MAX];
void del(int x)
{
	l[r[x]]=l[x];
	r[l[x]]=r[x];
}
int main()
{
	int n,i,ok,x,tot;
	ll fz,fm;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l[i]=i-1;
		r[i]=i+1;
		fa[i]=0;
		sz[i]=1;
		to[i][0]=to[i][1]=-1;
	}
	l[0]=0;
	r[0]=1;
	l[n+1]=n;
	r[n+1]=n+1;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			q.push(i);
			del(i);
		}
	}
	ok=1;
	tot=0;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		ord[x]=++tot;
		id[tot]=x;
		if(l[x]>=1)
		{
			if(a[l[x]]==0)
			{
				ok=0;
				break;
			}
			to[x][0]=l[x];
			a[l[x]]--;
			if(a[l[x]]==0)
			{
				q.push(l[x]);
				del(l[x]);
			}
		}
		if(r[x]<=n)
		{
			if(a[r[x]]==0)
			{
				ok=0;
				break;
			}
			to[x][1]=r[x];
			a[r[x]]--;
			if(a[r[x]]==0)
			{
				q.push(r[x]);
				del(r[x]);
			}
		}
	}
	if(tot!=n) ok=0;
	if(ok==0)
	{
		puts("0");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(to[i][0]==-1 && to[i][1]==-1) continue;
		if(to[i][0]==-1) fa[i]=to[i][1];
		else if(to[i][1]==-1) fa[i]=to[i][0];
		else
		{
			if(ord[to[i][0]]<ord[to[i][1]]) fa[i]=to[i][0];
			else fa[i]=to[i][1];
		}
	}
	for(i=1;i<=n;i++) sz[fa[id[i]]]+=sz[id[i]];
	fz=fm=1;
	for(i=1;i<=n;i++)
	{
		fz=fz*i%mod;
		fm=fm*sz[i]%mod;
	}
	printf("%lld\n",fz*inv(fm)%mod);
	return 0;
}
/*
5
0 2 2 0 1
ans=4

5
0 3 0 2 0
ans=8
*/
