#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int op,w,c;
	ll s1,s2;
	set<pair<int,int>> s;
	s1=s2=0;
	while(~scanf("%d",&op))
	{
		if(op==-1) break;
		if(op==1)
		{
			scanf("%d%d",&w,&c);
			if(s.size()>0 && (*s.lower_bound({c,0})).first==c) continue;
			s.insert({c,w});
			s1+=w;
			s2+=c;
		}
		else if(op==2)
		{
			if(s.size()==0) continue;
			s1-=(*s.rbegin()).second;
			s2-=(*s.rbegin()).first;
			s.erase(*s.rbegin());
		}
		else if(op==3)
		{
			if(s.size()==0) continue;
			s1-=(*s.begin()).second;
			s2-=(*s.begin()).first;
			s.erase(*s.begin());
		}
	}
	printf("%lld %lld\n",s1,s2);
	return 0;
}
