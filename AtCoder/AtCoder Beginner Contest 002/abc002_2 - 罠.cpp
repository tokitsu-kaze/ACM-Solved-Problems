#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1440+10;
int main()
{
	string tmp="aeiou";
	string s,now;
	cin>>s;
	for(auto &it:s)
	{
		if(tmp.find(it)!=tmp.npos) continue;
		now+=it;
	}
	cout<<now<<"\n";
	return 0;
}
