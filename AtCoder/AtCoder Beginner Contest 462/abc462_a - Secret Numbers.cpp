#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	string s,ans;
	cin>>s;
	for(auto &it:s)
	{
		if(it>='0' && it<='9') ans+=it;
	}
	cout<<ans<<"\n";
	return 0;
}
