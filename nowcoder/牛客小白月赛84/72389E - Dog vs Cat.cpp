#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
void assert_range(ll x,ll l,ll r){assert(x>=l&&x<=r);}
int a[MAX];
int main()
{
	int t,n,i,sumn,cnt0;
	int s;
	cin>>t;
	assert_range(t,1,1e6);
	sumn=0;
	while(t--)
	{
		scanf("%d",&n);
		assert_range(n,1,1e6);
		sumn+=n;
		assert_range(sumn,1,1e6);
		cnt0=0;
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			assert_range(a[i],0,1e9);
			if(a[i]==0) cnt0++;
			s+=a[i];
		}
		if(cnt0*2>=n||(n==2&&abs(a[1]-a[2])!=1))
		{
			puts("Dog");
			continue;
		}
		if((s-(n-(n+1)/2))&1) puts("Dog");
		else puts("Cat");
	}
	return 0;
}

