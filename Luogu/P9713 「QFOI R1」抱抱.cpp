#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int q,op,a,b,c,k,x,y,z;
	ll sum;
	scanf("%d%d%d%d",&a,&b,&c,&q);
	sum=1ll*a*b*c;
	x=y=z=0;
	while(q--)
	{
		scanf("%d%d",&op,&k);
		if(op==1)
		{
			sum-=1ll*
				max(0,min(k,a)-x)*
				max(0,b-y)*
				max(0,c-z);
			printf("%lld\n",sum);
			x=min(max(x,k),a);
		}
		else if(op==2)
		{
			sum-=1ll*
				max(0,a-x)*
				max(0,min(k,b)-y)*
				max(0,c-z);
			printf("%lld\n",sum);
			y=min(max(y,k),b);
		}
		else if(op==3)
		{
			sum-=1ll*
				max(0,a-x)*
				max(0,b-y)*
				max(0,min(k,c)-z);
			printf("%lld\n",sum);
			z=min(max(z,k),c);
		}
	}
	return 0;
}
