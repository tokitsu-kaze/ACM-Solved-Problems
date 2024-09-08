#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int i,n;
	string s,t;
	cin>>s>>t;
	vector<string> res;
	n=s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]<=t[i]) continue;
		s[i]=min(s[i],t[i]);
		res.push_back(s);
	}
	for(i=n-1;~i;i--)
	{
		if(s[i]>=t[i]) continue;
		s[i]=max(s[i],t[i]);
		res.push_back(s);
	}
	printf("%d\n",res.size());
	for(auto &it:res) cout<<it<<"\n";
	return 0;
}
