#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
int main()
{
	int n,m,i,j,cnt[105];
	scanf("%d%d",&n,&m);
	memset(cnt,0,sizeof cnt);
	for(i=1,j=1;i<=m;i++)
	{
		cnt[j]++;
		j++;
		if(j==n+1) j=1;
	}
	for(i=1;i<=n;i++) printf("%d\n",cnt[i]);
	return 0;
}
