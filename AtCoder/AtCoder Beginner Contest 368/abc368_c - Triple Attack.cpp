#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int main()
{
	int n,i,x;
	ll ans;
	scanf("%d",&n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans+=x/5*3;
		x%=5;
		while(x>0)
		{
			ans++;
			if(ans%3==0) x-=3;
			else x--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
