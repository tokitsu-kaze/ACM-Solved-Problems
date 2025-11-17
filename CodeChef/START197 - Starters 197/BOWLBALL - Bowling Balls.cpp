#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,a,x,y,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&x,&y);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(x<=a && a<=y) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
