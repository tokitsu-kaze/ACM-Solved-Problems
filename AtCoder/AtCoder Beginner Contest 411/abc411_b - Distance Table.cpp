#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,i,j,d[55],ans;
	scanf("%d",&n);
	for(i=2;i<=n;i++) scanf("%d",&d[i]);
	for(i=1;i<=n;i++)
	{
		ans=0;
		for(j=i+1;j<=n;j++)
		{
			ans+=d[j];
			printf("%d%c",ans," \n"[j==n]);
		}
	}
	return 0;
}
