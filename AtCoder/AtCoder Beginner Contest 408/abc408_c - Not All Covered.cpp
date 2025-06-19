#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int sum[MAX];
int main()
{
	int n,m,i,l,r,ans;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n+1;i++) sum[i]=0;
	while(m--)
	{
		scanf("%d%d",&l,&r);
		sum[l]++;
		sum[r+1]--;
	}
	for(i=1;i<=n;i++) sum[i]+=sum[i-1];
	ans=INF;
	for(i=1;i<=n;i++) ans=min(ans,sum[i]);
	printf("%d\n",ans);
	return 0;
}
