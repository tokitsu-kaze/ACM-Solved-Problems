#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,j,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<int> res[2];
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			res[x&1].push_back(x);
		}
		sort(res[1].begin(),res[1].end());
		ans=0;
		if(res[1].size())
		{
			ans+=res[1].back();
			res[1].pop_back();
			for(auto &it:res[0]) ans+=it;
			res[0].clear();
			i=0;
			j=res[1].size()-1;
			while(i<j)
			{
				i++;
				if(j>=i) ans+=res[1][j--];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
