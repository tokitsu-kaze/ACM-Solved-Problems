#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int N=1e7;
const int MAX=N+10;
int sum[MAX],ans[MAX];
int main()
{
	int T,x,i,j;
	for(i=0;i<=N;i++) sum[i]=0,ans[i]=-1;
	for(i=1;i<=N;i++)
	{
		for(j=i;j<=N;j+=i) sum[j]+=i;
		if(sum[i]<=N && ans[sum[i]]==-1) ans[sum[i]]=i;
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}
