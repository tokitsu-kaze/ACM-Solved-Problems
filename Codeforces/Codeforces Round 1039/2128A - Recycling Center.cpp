#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int T,n,i,ans,pos,x;
	ll c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&c);
		multiset<ll> s;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			s.insert(x);
		}
		ans=0;
		while(s.size()>0)
		{
			auto it=s.upper_bound(c);
			if(it==s.begin())
			{
				ans+=s.size();
				break;
			}
			it--;
			s.erase(it);
			multiset<ll> tmp;
			for(auto &it:s) tmp.insert(min(it*2,c+1));
			s=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
