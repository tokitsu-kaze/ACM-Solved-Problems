#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int pos[MAX];
int main()
{
	int n,q,i,id,x;
	scanf("%d%d",&n,&q);
	set<pair<int,int>> s;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s.insert({i,x});
		pos[x]=i;
	}
	id=n;
	while(q--)
	{
		scanf("%d",&x);
		s.erase({pos[x],x});
		pos[x]=++id;
		s.insert({pos[x],x});
	}
	i=0;
	for(auto &it:s)
	{
		i++;
		printf("%d%c",it.second," \n"[i==n]);
	}
	return 0;
}
