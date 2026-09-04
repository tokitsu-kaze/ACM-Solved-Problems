#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int n,q,i,op,x,ans;
	scanf("%d%d",&n,&q);
	ans=0;
	map<int,int> mp;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			ans^=mp[x];
			mp[x]++;
			ans^=mp[x];
		}
		else
		{
			vector<int> del;
			for(auto &it:mp)
			{
				ans^=it.second;
				it.second--;
				ans^=it.second;
				if(it.second==0) del.push_back(it.first);
			}
			for(auto &it:del) mp.erase(it);
		}
		printf("%d\n",ans);
	}
	return 0;
}
