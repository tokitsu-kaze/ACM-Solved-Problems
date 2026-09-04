#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int n,i,x,sum,cnt[105];
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]^=1;
	}
	sum=0;
	for(i=1;i<=100;i++) sum+=cnt[i]*i;
	printf("%d\n",sum);
	return 0;
}
