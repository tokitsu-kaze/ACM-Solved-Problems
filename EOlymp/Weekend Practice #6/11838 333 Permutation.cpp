#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int ans[MAX];
int main()
{
	int T,n,i,j,tot,pretot;
	scanf("%d",&T);
	while(T--)
	{
		vector<int> res[3];
		scanf("%d",&n);
		tot=0;
		if(n%6==3 || n%6==4)
		{
			ans[++tot]=n-2;
			for(i=1;i<n-2;i++) res[i%3].push_back(i);
			for(i=n-1;i<=n;i++) res[i%3].push_back(i);
		}
		else
		{
			for(i=1;i<=n;i++) res[i%3].push_back(i);
		}
		while(1)
		{
			pretot=tot;
			for(i=0;i<3;i++)
			{
				if(res[i].size()>=2)
				{
					for(j=0;j<2;j++)
					{
						ans[++tot]=res[i].back();
						res[i].pop_back();
					}
				}
			}
			if(pretot==tot) break;
		}
		for(i=0;i<3;i++)
		{
			while(res[i].size()>0)
			{
				ans[++tot]=res[i].back();
				res[i].pop_back();
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
		for(i=3;i<=n;i++) assert((ans[i-2]+ans[i-1]+ans[i])%3!=0);
	}
	return 0;
}
