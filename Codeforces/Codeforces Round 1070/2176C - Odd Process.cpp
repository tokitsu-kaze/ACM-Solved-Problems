#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int now_odd[MAX];
ll ans[MAX];
int main()
{
	int T,n,i,x;
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
		sort(res[0].begin(),res[0].end());
		sort(res[1].begin(),res[1].end());
		reverse(res[0].begin(),res[0].end());
		reverse(res[1].begin(),res[1].end());
		ans[0]=0;
		if(res[1].size())
		{
			ans[1]=res[1][0];
			now_odd[0]=0;
			now_odd[1]=1;
			for(i=2;i<=n;i++)
			{
				if(i-2<res[0].size())
				{
					ans[i]=ans[i-1]+res[0][i-2];
					now_odd[i]=now_odd[i-1];
				}
				else
				{
					if(now_odd[i-2]+2<=res[1].size())
					{
						ans[i]=ans[i-2];
						now_odd[i]=now_odd[i-2]+2;
					}
					else
					{
						ans[i]=0;
						now_odd[i]=INF;
					}
				}
			}
		}
		else
		{
			for(i=1;i<=n;i++) ans[i]=0;
		}
		for(i=1;i<=n;i++) printf("%lld%c",ans[i]," \n"[i==n]);
	}
	return 0;
}
