#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct node
{
	ll mn,now;
	int id;
	friend bool operator <(node x,node y)
	{
		return x.mn<y.mn;
	}
};
vector<int> a[MAX];
int main()
{
	int k,n,i;
	ll ans,mn,now;
	while(~scanf("%lld%d",&ans,&k))
	{
		priority_queue<node> q;
		for(i=1;i<=k;i++)
		{
			scanf("%d",&n);
			vector<int> tmp(n);
			for(auto &it:tmp) scanf("%d",&it);
			reverse(tmp.begin(),tmp.end());
			mn=LLINF;
			now=0;
			while(tmp.size()>0)
			{
				now+=tmp.back();
				tmp.pop_back();
				mn=min(mn,now);
				if(now>0) break;
			}
			if(now>0) q.push({mn,now,i});
			a[i]=tmp;
		}
		while(!q.empty())
		{
			auto t=q.top();
			q.pop();
			if(ans+t.mn>=0)
			{
				ans+=t.now;
				mn=LLINF;
				now=0;
				while(a[t.id].size()>0)
				{
					now+=a[t.id].back();
					a[t.id].pop_back();
					mn=min(mn,now);
					if(now>0) break;
				}
				if(now>0) q.push({mn,now,t.id});
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
