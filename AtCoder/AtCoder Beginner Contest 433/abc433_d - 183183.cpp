#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int n,m,i,j;
	ll ans,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	map<int,int> mp[11];
	for(i=1;i<=n;i++)
	{
		string tmp=to_string(a[i]);
		mp[tmp.size()][a[i]%m]++;
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		x=a[i];
		for(j=1;j<=10;j++)
		{
			x=x*10%m;
			if(mp[j].count((m-x)%m)) ans+=mp[j][(m-x)%m];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
