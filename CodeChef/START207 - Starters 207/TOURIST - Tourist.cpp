#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,a,b,x,y,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&a,&b);
		ans=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			ans=min(ans,abs(a-x)+abs(b-y));
		}
		printf("%d\n",ans);
	}
	return 0;
}
