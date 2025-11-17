#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	string s;
	cin>>s;
	map<char,int> mp;
	for(auto &it:s) mp[it]++;
	if(mp['c']==1 && mp['a']==1 && mp['t']==1) puts("Yes");
	else puts("No");
	return 0;
}
