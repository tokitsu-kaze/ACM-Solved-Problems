#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	int T,n,i,a[55],ans,pre;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		pre=-1;
		for(i=1;i<=n;i++)
		{
			if(a[i])
			{
				if(pre>0) ans+=i-pre-1;
				pre=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
