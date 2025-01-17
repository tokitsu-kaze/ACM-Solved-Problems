#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int a[111],b[111];
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		ans=0;
		b[n+1]=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]-b[i+1]>0) ans+=a[i]-b[i+1];
		}
		printf("%d\n",ans);
	}
	return 0;
}
