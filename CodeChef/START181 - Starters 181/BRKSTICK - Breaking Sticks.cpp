#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int T,n,x,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ans+=x-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
