#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int a[MAX];
int main()
{
	int T,n,i,j,l,r;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(i=1;i<n-1;i++)
		{
			for(j=i+1,l=n+1,r=i+2;j<n;j++)
			{
				r=max(j+1,r);
				l=upper_bound(a+j+1,a+1+n,a[n]-a[i]-a[j])-a;
				while(r<n && a[r+1]<a[i]+a[j]) r++;
				if(l<=r && r<=n && a[r]<a[i]+a[j] && a[i]+a[j]+a[l]>a[n]) ans+=r-l+1;
//				cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
