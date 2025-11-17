#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int a[MAX];
int main()
{
	int T,n,i,ans,now,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(x=1;x<=100;x++)
		{
			now=0;
			for(i=1;i<=n;i++)
			{
				now-=x*30;
				now+=min(x,a[i])*50;
			}
			ans=max(ans,now);
		}
		printf("%d\n",ans);
	}
	return 0;
}
