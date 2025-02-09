#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-12;
const int MAX=3e5+10;
vector<int> pos[MAX];
int a[MAX];
int main()
{
	int n,i,l,r;
	ll ans;
	scanf("%d",&n);
	for(i=0;i<=n+1;i++)
	{
		pos[i].clear();
		pos[i].push_back(0);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]].push_back(i);
	}
	for(i=0;i<=n+1;i++) pos[i].push_back(n+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		l=max({*(--lower_bound(pos[a[i]].begin(),pos[a[i]].end(),i)),
			   *(--lower_bound(pos[a[i]-1].begin(),pos[a[i]-1].end(),i))});
		r=*upper_bound(pos[a[i]-1].begin(),pos[a[i]-1].end(),i);
		ans+=1LL*(i-l)*(r-i);
//		printf("%d %d %d %lld\n",i,l,r,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
