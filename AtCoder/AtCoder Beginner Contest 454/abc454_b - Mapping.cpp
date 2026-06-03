#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int n,m,i,cnt[105],x,ra,rb;
	scanf("%d%d",&n,&m);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	ra=rb=1;
	for(i=1;i<=m;i++)
	{
		if(cnt[i]>=2) ra=0;
		if(cnt[i]==0) rb=0;
	}
	if(ra) puts("Yes");
	else puts("No");
	if(rb) puts("Yes");
	else puts("No");
	return 0;
}
