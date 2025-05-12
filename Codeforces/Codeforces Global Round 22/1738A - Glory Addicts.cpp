#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			ans+=b[i];
		}
		vector<int> res[2];
		for(i=1;i<=n;i++) res[a[i]].push_back(b[i]);
		sort(res[0].begin(),res[0].end());
		reverse(res[0].begin(),res[0].end());
		sort(res[1].begin(),res[1].end());
		reverse(res[1].begin(),res[1].end());
		if(res[0].size()<res[1].size()) swap(res[0],res[1]);
		for(i=0;i<res[1].size();i++) ans+=res[0][i]+res[1][i];
		if(res[0].size()==res[1].size()) ans-=min(res[0].back(),res[1].back());
		printf("%lld\n",ans);
	}
	return 0;
}

