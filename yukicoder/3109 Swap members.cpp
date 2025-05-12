#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
map<string,int> mp[MAX];
int main()
{
	int n,k,i,ok;
	string s;
	scanf("%d%d",&n,&k);
	for(i=0;i<k;i++) mp[i].clear();
	for(i=0;i<n;i++)
	{
		cin>>s;
		mp[i%k][s]++;
	}
	for(i=0;i<n;i++)
	{
		cin>>s;
		mp[i%k][s]--;
		if(mp[i%k][s]==0) mp[i%k].erase(s);
	}
	ok=1;
	for(i=0;i<k;i++)
	{
		if(mp[i].size()>0) ok=0;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
