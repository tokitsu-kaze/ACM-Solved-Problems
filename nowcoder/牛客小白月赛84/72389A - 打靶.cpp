#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void assert_range(ll x,ll l,ll r){assert(x>=l&&x<=r);}
int main()
{
	int t,n,m,x,y;
	cin>>t;
	assert_range(t,1,100);
	while(t--)
	{
		cin>>n>>m>>x>>y;
		assert_range(n,1,1e6);
		assert_range(m,1,n);
		assert_range(x,0,m);
		assert_range(y,0,1e9);
		if(y>=x&&y<=x+(n-m)) puts("Yes");
		else puts("No");
	}
	return 0;
}
