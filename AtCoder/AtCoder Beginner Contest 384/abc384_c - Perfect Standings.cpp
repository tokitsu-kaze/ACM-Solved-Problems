#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=50000+10;
const int mod=998244353;
vector<pair<int,string>> res;
int a[6];
const int n=5;
void dfs(int x,int v,string now)
{
	if(x==n)
	{
		if(now.size()==0) return;
		res.push_back({-v,now});
		return;
	}
	char tmp=x+'A';
	dfs(x+1,v+a[x],now+tmp);
	dfs(x+1,v,now);
}
int main()
{
	int i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	dfs(0,0,"");
	sort(res.begin(),res.end());
	for(auto &it:res) cout<<it.second<<"\n";
	return 0;
}
