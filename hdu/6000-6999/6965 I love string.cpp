#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1000000007;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,n,cnt,ans;
	string s;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cin>>s;
		cnt=0;
		for(auto &ch:s)
		{
			if(ch==s[0]) cnt++;
			else break;
		}
		ans=1;
		cnt--;
		while(cnt--) ans=ans*2LL%mod;
		cout<<ans<<"\n";
	}
	return 0;
}
