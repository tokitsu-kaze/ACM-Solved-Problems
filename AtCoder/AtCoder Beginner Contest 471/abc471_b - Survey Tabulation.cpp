#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,mx;
	string s;
	scanf("%d",&n);
	map<string,int> mp;
	mx=0;
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(auto &ch:s)
		{
			if('A'<=ch && ch<='Z') ch=ch-'A'+'a';
		}
		mp[s]++;
		mx=max(mx,mp[s]);
	}
	printf("%d\n",mx);
	return 0;
}
