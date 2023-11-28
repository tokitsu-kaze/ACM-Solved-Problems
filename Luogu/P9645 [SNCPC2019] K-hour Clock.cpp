#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int main()
{
	int t;
	ll x,y,z,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		if(x+y==z) printf("%lld\n",z+1);
		else if(x+y<z) puts("-1");
		else if(x+y>z)
		{
			k=x+y-z;
			if((x+y)%k!=z||k<=x) puts("-1");
			else printf("%lld\n",k);
		}
	}
	return 0;
}
/*
(x+y)%k=z
100
1 5 4
*/

