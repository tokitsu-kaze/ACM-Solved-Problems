#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int n,m,i,a,b,cnt[105];
	memset(cnt,0,sizeof cnt);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		cnt[a]--;
		cnt[b]++;
	}
	for(i=1;i<=m;i++) printf("%d\n",cnt[i]);
	return 0;
}
