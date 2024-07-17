#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int n,i,mn;
	ll ans;
	scanf("%d",&n);
	mn=INF;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mn=min(mn,a[i]);
	}
	ans=1;
	for(i=1;i<=n;i++) ans=ans*(a[i]/mn)%mod;
	printf("%d %lld\n",mn,ans);
	return 0;
}
