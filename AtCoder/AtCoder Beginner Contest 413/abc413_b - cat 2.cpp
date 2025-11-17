#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
int main()
{
	int n,i,j;
	string s[105];
	map<string,int> mp;
	cin>>n;
	for(i=1;i<=n;i++) cin>>s[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			mp[s[i]+s[j]]=1;
		}
	}
	cout<<mp.size()<<"\n";
	return 0;
}
