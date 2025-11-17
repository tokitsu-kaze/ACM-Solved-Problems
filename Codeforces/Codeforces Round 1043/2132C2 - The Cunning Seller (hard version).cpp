#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
struct node{ll cnt,sd,x;};
int main()
{
	int T,n,k,i;
	ll ans,sd,x,tot,now,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		ans=0;
		sd=1;
		x=0;
		vector<node> res;
		tot=0;
		while(n)
		{
			res.push_back({n%3,sd,x});
			tot+=n%3;
			n/=3;
			sd*=3;
			x++;
		}
		if(tot>k)
		{
			puts("-1");
			continue;
		}
		reverse(res.begin(),res.end());
		ans=now=0;
		for(auto &it:res)
		{
			tot-=it.cnt;
			now+=it.cnt;
			if(now*3+tot>k)
			{
				tmp=min(now,(3*now+tot-k+1)/2);
				ans+=tmp*((it.sd*3)+it.x*it.sd/3);
				k-=tmp;
				now-=tmp;
			}
			if(it.x==0)
			{
				ans+=now*((it.sd*3)+it.x*it.sd/3);
				k-=now;
				now=0;
			}
			now*=3;
		}
		assert(k>=0);
		printf("%lld\n",ans);
	}
	return 0;
}

