#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void assert_range(ll x,ll l,ll r){assert(x>=l&&x<=r);}
int main()
{
	int t,x,y;
	cin>>t;
	assert_range(t,1,100);
	while(t--)
	{
		cin>>x>>y;
		assert_range(x,1,1e5);
		assert_range(y,1,1e5);
		if(y%x==0) printf("%d %d\n",x,y);
		else puts("-1");
	}
	return 0;
}
