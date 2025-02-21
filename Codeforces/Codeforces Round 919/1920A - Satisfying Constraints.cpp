#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,op,x,i,mx,mn,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		mx=0;
		mn=1e9;
		vector<int> res;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&op,&x);
			if(op==1) mx=max(mx,x);
			else if(op==2) mn=min(mn,x);
			else res.push_back(x);
		}
		ans=max(0,mn-mx+1);
		for(auto &it:res)
		{
			if(it>=mx && it<=mn) ans--;
		}
		ans=max(0,ans);
		printf("%d\n",ans);
	}
	return 0;
}
