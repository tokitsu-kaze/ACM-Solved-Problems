#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int mp[110][110];
int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	set<pair<int,int>> s;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		if(s.count({x,y})) continue;
		if(s.count({x+1,y})) continue;
		if(s.count({x,y+1})) continue;
		if(s.count({x+1,y+1})) continue;
		s.insert({x,y});
		s.insert({x+1,y});
		s.insert({x,y+1});
		s.insert({x+1,y+1});
	}
	printf("%d\n",(int)s.size()/4);
	return 0;
}
