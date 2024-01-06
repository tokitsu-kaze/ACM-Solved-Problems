#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
void assert_range(ll x,ll l,ll r){assert(x>=l&&x<=r);}
int a[MAX];
int main()
{
	int t,n,k,i,sumn,b,ok;
	cin>>t;
	assert_range(t,1,1e5);
	sumn=0;
	while(t--)
	{
		cin>>n>>k;
		assert_range(n,1,2e5);
		assert_range(k,0,1e9);
		sumn+=n;
		assert_range(sumn,1,1e6);
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			assert_range(a[i],-1e9,1e9);
		}
		ok=1;
		b=2e9;
		for(i=n;i;i--)
		{
			b=min(b,a[i]+k);
			if(abs(b-a[i])>k) ok=0;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
