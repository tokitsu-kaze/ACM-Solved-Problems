#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int t,n,m,k,i,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		set<int> ra,rb,res;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x<=k)
			{
				ra.insert(x);
				res.insert(x);
			}
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			if(x<=k)
			{
				rb.insert(x);
				res.insert(x);
			}
		}
		if(res.size()!=k || ra.size()<k/2 || rb.size()<k/2) puts("NO");
		else puts("YES");
	}
	return 0;
}
