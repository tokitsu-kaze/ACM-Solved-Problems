#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int n,k,i,p;
	string s,ans;
	cin>>n>>k;
	cin>>s;
	p=1;
	for(i=0;i<n;i++)
	{
		if(s[i]<s[i%p]) p=i+1;
		else if(s[i]>s[i%p]) break;
	}
	ans="";
	while(ans.size()<k) ans+=s.substr(0,p);
	while(ans.size()>k) ans.pop_back();
	cout<<ans<<"\n";
	return 0;
}

