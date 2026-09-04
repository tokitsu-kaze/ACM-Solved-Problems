#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int cnt[MAX];
int main()
{
	int T,n,m,i,j,x,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&x);
				cnt[x]++;
			}
		}
		ok=0;
		for(i=1;i<=n;i++)
		{
			if(cnt[i]>m) ok=1;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
