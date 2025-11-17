#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int a[MAX];
ll sum[MAX];
int main()
{
	int n,q,i,op,l,r,len,c,x,y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=n+1;i<=2*n;i++) a[i]=a[i-n];
	sum[0]=0;
	for(i=1;i<=2*n;i++) sum[i]=sum[i-1]+a[i];
	x=1;
	y=n;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&c);
			x+=c;
			y+=c;
			if(x>n)
			{
				x-=n;
				y-=n;
			}
		}
		else
		{
			scanf("%d%d",&l,&r);
			len=r-l+1;
			l=x+l-1;
			r=l+len-1;
			printf("%lld\n",sum[r]-sum[l-1]);
		}
	}
	return 0;
}
