#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,pos;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(i=1;i<n;i++) ans+=a[i];
		pos=n;
		for(i=1;i<n;i++)
		{
			if(a[i]>0)
			{
				pos=i;
				break;
			}
		}
		for(i=pos;i<n;i++)
		{
			if(a[i]==0) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
