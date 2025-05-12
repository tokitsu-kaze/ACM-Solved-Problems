#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<17)+10;
int a[MAX];
int main()
{
	int T,n,i,j,l,r,cnt,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&l,&r);
		n=r-l+1;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(j=0;j<=17;j++)
		{
			cnt=0;
			for(i=l;i<=r;i++) cnt+=((i>>j)&1);
			for(i=1;i<=n;i++) cnt-=((a[i]>>j)&1);
			if(cnt!=0) ans|=(1<<j);
		}
		for(i=1;i<=n;i++) a[i]^=ans;
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++) assert(a[i]==i+l-1);
		printf("%d\n",ans);
	}
	return 0;
}

