#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,now,ans;
	string s;
	cin>>n;
	ans=0;
	now=0;
	while(n--)
	{
		cin>>s;
		if(s=="login") now=1;
		else if(s=="logout") now=0;
		else if(s=="private")
		{
			if(now==0) ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
