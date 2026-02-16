#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,k,i,j,mx;
	string s;
	cin>>n>>k;
	cin>>s;
	map<string,int> mp;
	for(i=0;i<n-k+1;i++)
	{
		string tmp=s.substr(i,k);
		if(mp.count(tmp)) continue;
		for(j=0;j<n-k+1;j++)
		{
			if(tmp==s.substr(j,k)) mp[tmp]++;
		}
	}
	mx=0;
	for(auto &it:mp) mx=max(mx,it.second);
	vector<string> res;
	for(auto &it:mp)
	{
		if(it.second==mx) res.push_back(it.first);
	}
	sort(res.begin(),res.end());
	cout<<mx<<"\n";
	i=0;
	for(auto &it:res)
	{
		cout<<it;
		i++;
		if(i==res.size()) cout<<"\n";
		else cout<<" ";
	}
	return 0;
}
