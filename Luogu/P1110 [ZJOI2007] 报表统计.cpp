#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
vector<int> mp[MAX];
int main()
{
	int n,m,i,x,pos;
	char op[22];
	scanf("%d%d",&n,&m);
	multiset<int> s,sa,sb;
	s.insert(-INF);
	s.insert(INF);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		scanf("%d",&x);
		mp[i].push_back(x);
		sb.insert((*s.lower_bound(x))-x);
		sb.insert(x-*(--s.upper_bound(x)));
		s.insert(x);
	}
	for(i=1;i<n;i++) sa.insert(abs(mp[i][0]-mp[i+1][0]));
	while(m--)
	{
		scanf("%s",op);
		if(op[0]=='I')
		{
			scanf("%d%d",&pos,&x);
			sb.insert((*s.lower_bound(x))-x);
			sb.insert(x-*(--s.upper_bound(x)));
			s.insert(x);
			if(pos<n) sa.erase(sa.find(abs(mp[pos].back()-mp[pos+1][0])));
			sa.insert(abs(mp[pos].back()-x));
			mp[pos].push_back(x);
			if(pos<n) sa.insert(abs(x-mp[pos+1][0]));
		}
		else if(op[0]=='M' && op[4]=='G') printf("%d\n",*sa.begin());
		else printf("%d\n",*sb.begin());
	}
	return 0;
}
