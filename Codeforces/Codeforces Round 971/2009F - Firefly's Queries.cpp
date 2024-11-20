#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
int a[MAX];
ll bit[MAX];
int main()
{
	int T,n,q,i,x,y;
	ll ans,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			bit[i]=bit[i-1]+a[i];
		}
		for(i=n+1;i<=2*n;i++) bit[i]=bit[i-1]+a[i-n];
		while(q--)
		{
			scanf("%lld%lld",&l,&r);
			l--;
			r--;
			ans=0;
			if(l/n==r/n)
			{
				x=l/n+l%n;
				y=x+(r-l+1)-1;
				x++;
				y++;
				ans+=bit[y]-bit[x-1];
				printf("%lld\n",ans);
				continue;
			}
			if(l%n)
			{
				x=l/n+l%n;
				y=x+(n-l%n)-1;
				l=(l/n+1)*n-1;
				x++;
				y++;
//				cout<<x<<" "<<y<<endl;
				ans+=bit[y]-bit[x-1];
			}
			if((r+1)%n)
			{
				x=r/n;
				y=x+r%n;
				r=1LL*x*n-1;
				x++;
				y++;
				ans+=bit[y]-bit[x-1];
			}
//			cout<<l<<" "<<r<<endl;
			ans+=((r-l+1)/n)*bit[n];
			printf("%lld\n",ans);
		}
	}
	return 0;
}

