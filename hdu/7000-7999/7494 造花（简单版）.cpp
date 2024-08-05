#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
vector<int> mp[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n,i,ok,la,lb,ra,rb,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			cin>>a>>b;
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		ok=0;
		for(i=1;i<=n;i++)
		{
			if(mp[i].size()!=2) continue;
			la=mp[mp[i][0]].size();
			ra=mp[mp[i][1]].size();
			if(la+ra+1==n) ok=1;
			if(la==2)
			{
				for(auto &it:mp[mp[i][0]])
				{
					if(it==i) continue;
					lb=mp[it].size()+1;
				}
			}
			else lb=0;
			if(ra==2)
			{
				for(auto &it:mp[mp[i][1]])
				{
					if(it==i) continue;
					rb=mp[it].size()+1;
				}
			}
			else rb=0;
			if(la+rb+1==n) ok=1;
			if(ra+lb+1==n) ok=1;
			if(lb+rb+1==n) ok=1;
		}
		cout<<(ok?"Yes\n":"No\n");
	}
	return 0;
}
/*
2
6
1 2
2 3
3 4
3 5
1 6
8
1 2
2 3
3 4
3 5
1 6
6 7
7 8
*/
