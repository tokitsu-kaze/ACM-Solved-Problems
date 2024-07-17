#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int flag[55];
int main()
{
	int t,n,m,tmp;
	ll now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		tmp=n;
		now=1;
		while(tmp%10==0) tmp/=10;
		while(tmp%5==0)
		{
			tmp/=5;
			if(now*2<=m) now*=2;
		}
		while(tmp%2==0)
		{
			tmp/=2;
			if(now*5<=m) now*=5;
		}
		while(now*10<=m) now*=10;
		if(m/now>0) now=m/now*now;
		if(n*now%10) printf("%lld\n",1LL*n*m);
		else printf("%lld\n",n*now);
	}
	return 0;
}
