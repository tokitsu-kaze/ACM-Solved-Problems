#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
const int mod=1e9+7;
int a[MAX],v[MAX],now[MAX];
int go[62][MAX];
int main()
{
	int n,i,j;
	ll k;
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&go[0][i]);
	for(i=1;i<=n;i++) scanf("%d",&v[i]);
	for(j=1;j<=61;j++)
	{
		for(i=1;i<=n;i++)
		{
			go[j][i]=go[j-1][go[j-1][i]];
		}
	}
	for(i=1;i<=n;i++) now[i]=i;
	for(i=0;i<=61;i++)
	{
		if(!((k>>i)&1)) continue;
		for(j=1;j<=n;j++) now[j]=go[i][now[j]];
	}
	for(i=1;i<=n;i++) printf("%d%c",v[now[i]]," \n"[i==n]);
	return 0;
}
