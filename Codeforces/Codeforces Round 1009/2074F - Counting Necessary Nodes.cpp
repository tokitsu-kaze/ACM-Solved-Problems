#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int ql,qr;
vector<int> res;
void dfs(int l,int r)
{
	if(l>=ql&&r<=qr)
	{
		res.push_back(r-l+1);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) dfs(l,mid);
	if(qr>mid) dfs(mid+1,r);
}
int main()
{
	int T,l1,r1,l2,r2;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		vector<int> ra,rb;
		res.clear();
		ql=l1;qr=r1-1;
		dfs(0,(1<<21)-1);
		ra=res;
		
		res.clear();
		ql=l2;qr=r2-1;
		dfs(0,(1<<21)-1);
		rb=res;
		
		ans=0;
		for(auto &x:ra)
		{
			for(auto &y:rb)
			{
				ans+=max(x,y)/min(x,y);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
