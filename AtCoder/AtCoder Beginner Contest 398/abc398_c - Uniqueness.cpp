#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int n,i,x;
	scanf("%d",&n);
	map<int,int> mp,pos;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mp[x]++;
		if(mp[x]==1) pos[x]=i;
		else pos.erase(x);
	}
	if(pos.size()==0) puts("-1");
	else printf("%d\n",(*pos.rbegin()).second);
	return 0;
}
