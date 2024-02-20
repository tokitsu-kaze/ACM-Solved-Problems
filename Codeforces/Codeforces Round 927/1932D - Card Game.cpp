#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=4e5+10;
char s[2],tmp[5];
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		map<char,vector<string>> mp;
		for(i=0;i<2*n;i++)
		{
			scanf("%s",tmp);
			mp[tmp[1]].push_back(tmp);
		}
		for(auto &it:mp)
		{
			sort(it.second.begin(),it.second.end());
			reverse(it.second.begin(),it.second.end());
		}
		vector<pair<string,string>> res;
		for(auto &it:mp)
		{
			if(it.first==s[0]) continue;
			if(it.second.size()%2)
			{
				if(mp[s[0]].size())
				{
					res.push_back({it.second.back(),mp[s[0]].back()});
					it.second.pop_back();
					mp[s[0]].pop_back();
				}
			}
			for(i=1;i<it.second.size();i+=2)
			{
				res.push_back({it.second[i],it.second[i-1]});
			}
			it.second.clear();
		}
		for(auto &it:mp)
		{
			for(i=1;i<it.second.size();i+=2)
			{
				res.push_back({it.second[i],it.second[i-1]});
			}
		}
		if(res.size()!=n) puts("IMPOSSIBLE");
		else
		{
			for(auto &it:res) cout<<it.first<<" "<<it.second<<"\n";
		}
	}
	return 0;
}
