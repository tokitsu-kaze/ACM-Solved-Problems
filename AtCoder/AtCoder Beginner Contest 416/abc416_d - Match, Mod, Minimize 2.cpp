#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,m,i,j;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		sort(b+1,b+1+n);
		for(i=1,j=0;i<=n;i++)
		{
			while(j<=n && a[i]+b[j]<m) j++;
			if(j<=n && a[i]+b[j]>=m)
			{
				b[j]-=m;
				j++;
			}
		}
		ans=0;
		for(i=1;i<=n;i++) ans+=a[i]+b[i];
		printf("%lld\n",ans);
	}
	return 0;
}
