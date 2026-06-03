#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
int vis[MAX],n,m,ok;
void dfs(int x,int fa)
{
	int k,tmp;
	vis[x]=1;
	if(ok) return;
	if(x==n)
	{
		ok=1;
		return;
	}
	scanf("%d",&k);
	vector<int> mp(k);
	for(auto &to:mp) scanf("%d",&to);
	for(auto &to:mp)
	{
		if(vis[to]) continue;
		printf("%d\n",to);
		fflush(stdout);
		dfs(to,x);
		if(ok) return;
	}
	printf("%d\n",fa);
	fflush(stdout);
	scanf("%d",&k);
	while(k--) scanf("%d",&tmp);
}
int main()
{
	scanf("%d%d",&n,&m);
	ok=0;
	dfs(1,0);
	string s;
	cin>>s;
	return 0;
}
