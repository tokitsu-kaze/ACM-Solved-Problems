#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll sum[MAX];
int a[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q,i;
	ll x;
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	sum[0]=0;
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	while(q--)
	{
		cin>>x;
		cout<<(upper_bound(sum+1,sum+1+n,x)-sum-1)<<"\n";
	}
	return 0;
}
