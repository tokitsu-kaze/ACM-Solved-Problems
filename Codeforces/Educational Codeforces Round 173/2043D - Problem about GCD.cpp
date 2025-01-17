#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=1e9+7;
int main()
{
	int T;
	ll l,r,g,nl,nr,ansl,ansr,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&l,&r,&g);
		ansl=-1;
		ansr=-2;
		nl=(l+g-1)/g;
		nr=r/g;
		for(i=nl;i<=min(nr,nl+50);i++)
		{
			for(j=nr;j>=i;j--)
			{
				if(__gcd(i,j)==1)
				{
					if((j-i)*g>ansr-ansl)
					{
						ansl=i*g;
						ansr=j*g;
					}
					break;
				}
			}
		}
		if(ansl==-1) ansl=ansr=-1;
		printf("%lld %lld\n",ansl,ansr);
	}
	return 0;
}

