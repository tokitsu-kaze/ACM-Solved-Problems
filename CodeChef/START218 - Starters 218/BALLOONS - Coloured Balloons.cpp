#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int T,n,i,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ans+=i*x;
		}
		printf("%d\n",ans);
	}
	return 0;
}
