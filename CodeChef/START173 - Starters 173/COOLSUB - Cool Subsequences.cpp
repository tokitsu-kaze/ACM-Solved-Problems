#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int T,n,i,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		map<int,int> mp;
		ans=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x]++;
			if(mp[x]==2) ans=x;
		}
		if(ans==-1) puts("-1");
		else
		{
			puts("1");
			printf("%d\n",ans);
		}
	}
	return 0;
}
