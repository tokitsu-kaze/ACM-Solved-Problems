#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,k,a,b,ans;
	cin>>n>>k;
	cin>>a>>b;
	ans=0;
	while(n>1)
	{
		if(n<k || k==1)
		{
			ans+=a*(n-1);
			n=1;
			break;
		}
		if(n%k) // n>k
		{
			ans+=a*(n-n/k*k);
			n=n/k*k;
		}
		else
		{
			ans+=min(a*(n-n/k),b);
			n/=k;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
