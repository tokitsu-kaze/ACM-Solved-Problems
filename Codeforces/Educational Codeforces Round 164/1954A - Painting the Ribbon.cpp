#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,m,k,i,j,cnt[55],mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		memset(cnt,0,sizeof cnt);
		j=1;
		for(i=1;i<=n;i++)
		{
			cnt[j]++;
			j++;
			if(j==m+1) j=1;
		}
		mx=0;
		for(i=1;i<=m;i++) mx=max(mx,cnt[i]);
		if(k+mx>=n) puts("NO");
		else puts("YES");
	}
	return 0;
}
