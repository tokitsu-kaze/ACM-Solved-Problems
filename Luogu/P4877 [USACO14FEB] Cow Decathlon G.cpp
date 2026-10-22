#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<20)+10;
struct node{int p,a;};
vector<node> ex[22];
int v[22][22],dp[MAX];
int main()
{
	int n,m,i,j,k,p,a,s,now;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) ex[i].clear();
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&k,&p,&a);
		ex[k-1].push_back({p,a});
	}
	for(i=0;i<n;i++)
	{
		sort(ex[i].begin(),ex[i].end(),[](node x,node y){
			return x.p<y.p;
		});
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) scanf("%d",&v[i][j]);
	}
	memset(dp,0,sizeof dp);
	for(s=0;s<(1<<n);s++)
	{
		for(j=0;j<n;j++)
		{
			if(!((s>>j)&1)) continue;
			p=__builtin_popcount(s);
			now=dp[s^(1<<j)]+v[j][p-1];
			for(auto &it:ex[p-1]) if(now>=it.p) now+=it.a;
			dp[s]=max(dp[s],now);
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
	return 0;
}
/*
Ö±½Ó×´Ñ¹dp¼´¿É¡£
*/
