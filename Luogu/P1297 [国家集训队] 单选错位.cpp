#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,i;
	ll a1,a,b,c,now,pre,x,y;
	double ans;
	scanf("%d%lld%lld%lld%lld",&n,&a,&b,&c,&a1);
	ans=0;
	pre=a1;
	for(i=2;i<=n;i++)
	{
		now=(pre*a+b)%100000001;
		x=pre%c+1;
		y=now%c+1;
		ans+=1.0*min(x,y)/(x*y);
		pre=now;
	}
	x=a1%c+1;
	y=now%c+1;
	ans+=1.0*min(x,y)/(x*y);
	printf("%.3f\n",ans);
	return 0;
}
