#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<int> res[2];
		for(i=1;i<=2*n;i++)
		{
			scanf("%d",&x);
			res[i&1].push_back(x);
		}
		sort(res[0].begin(),res[0].end());
		sort(res[1].begin(),res[1].end());
		reverse(res[1].begin(),res[1].end());
		ans=0;
		for(i=0;i<n;i++) ans+=abs(res[0][i]-res[1][i]);
		printf("%lld\n",ans);
	}
	return 0;
}
