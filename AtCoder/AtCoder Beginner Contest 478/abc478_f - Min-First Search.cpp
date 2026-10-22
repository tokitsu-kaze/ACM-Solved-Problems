#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int st[MAX];
void workl(int *x,int n,int *l)
{
	int i,top;
	top=0;
	for(i=n;i;i--)
	{
		while(top && x[st[top-1]]<x[i]) l[st[--top]]=i;
		st[top++]=i;
	}
	while(top>0) l[st[--top]]=1;
}
int p[MAX],l[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	workl(p,n,l);
	ans=1;
	for(i=2;i<=n;i++) ans=ans*(i-l[i])%mod;
	printf("%lld\n",ans);
	return 0;
}
