#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> pos[MAX];
int main()
{
	int T,n,i,x,now,ra,rb;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) pos[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			pos[min(x,n/2)].push_back(i);
		}
		ans=0;
		set<int> s,sl,sr;
		for(i=n/2;i;i--)
		{
			for(auto &p:pos[i]) s.insert(p);
			if(s.size()==0) continue;
			if(s.size()>=2) now=*s.rbegin()-*s.begin();
			else now=0;
			if(sl.size()>0) ra=*sl.rbegin()-*s.begin();
			else ra=0;
			if(sr.size()>0) rb=*s.rbegin()-*sr.begin();
			else rb=0;
			if(max({now,ra,rb})==0) continue;
			ans+=max({now,ra,rb});
			if(now>=max(ra,rb))
			{
				sl.insert(*s.begin());
				sr.insert(*s.rbegin());
				s.erase(*s.begin());
				s.erase(*s.rbegin());
			}
			else if(ra>=max(now,rb))
			{
				s.insert(*sl.rbegin());
				sl.insert(*s.begin());
				sl.erase(*sl.rbegin());
				s.erase(*s.begin());
			}
			else if(rb>=max(now,ra))
			{
				sr.insert(*s.rbegin());
				s.insert(*sr.begin());
				s.erase(*s.rbegin());
				sr.erase(*sr.begin());
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
4
1 1 2 2
*/

