#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
int main()
{
	int n,m,i,x;
	while(~scanf("%d%d",&n,&m))
	{
		vector<int> ans;
		while(n--)
		{
			scanf("%d",&x);
			ans.pb(x);
		}
		while(m--)
		{
			scanf("%d",&x);
			ans.pb(x);
		}
		sort(all(ans));
		if(sz(ans))
		{
			printf("%d",ans[0]);
			for(i=1;i<sz(ans);i++) printf(" %d",ans[i]);
			if((int)sz(ans)>1) puts("");	
		}
	}
	return 0;
} 