#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,k,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		vector<int> res;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=max(a[i],b[i]);
			res.push_back(min(a[i],b[i]));
		}
		sort(res.begin(),res.end());
		reverse(res.begin(),res.end());
		for(i=0;i<k-1;i++) ans+=res[i];
		printf("%lld\n",ans+1);
	}
	return 0;
}

