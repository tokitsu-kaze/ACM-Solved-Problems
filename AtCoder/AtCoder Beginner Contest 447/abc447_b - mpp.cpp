#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	string s;
	map<char,int> mp;
	cin>>s;
	for(auto &it:s) mp[it]++;
	int mx=0;
	for(auto &it:mp) mx=max(mx,it.second);
	string res="";
	for(auto &it:s)
	{
		if(mp[it]!=mx) res+=it;
	}
	cout<<res<<"\n";
	return 0;
}
