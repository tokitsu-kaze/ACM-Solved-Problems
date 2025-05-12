#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,ans;
	ull x;
	scanf("%d%llu",&n,&x);
	map<ull,int> mp;
	queue<ull> q;
	mp[x]=0;
	q.push(x);
	ans=-1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		string tmp=to_string(x);
		if(tmp.size()==n)
		{
			ans=mp[x];
			break;
		}
		for(auto &it:tmp)
		{
			if(mp.count(x*(it-'0'))) continue;
			mp[x*(it-'0')]=mp[x]+1;
			q.push(x*(it-'0'));
		}
	}
	printf("%d\n",ans);
	return 0;
}

