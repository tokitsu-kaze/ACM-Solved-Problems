#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int n,k,i;
	string s,now,ans;
	cin>>n>>k;
	cin>>s;
	ans="";
	while(ans.size()<k) ans+=s;
	while(ans.size()>k) ans.pop_back();
	for(i=1;i<n;i++)
	{
		now="";
		while(now.size()<k) now+=s.substr(0,i);
		while(now.size()>k) now.pop_back();
		ans=min(ans,now);
	}
	cout<<ans<<"\n";
	return 0;
}

