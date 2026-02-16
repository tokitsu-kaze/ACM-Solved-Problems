#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	string s,res;
	cin>>s;
	for(auto &it:s)
	{
		if(it>='0'&&it<='9') res+=it;
	}
	sort(res.begin(),res.end());
	reverse(res.begin(),res.end());
	cout<<res<<"\n";
	return 0;
}
