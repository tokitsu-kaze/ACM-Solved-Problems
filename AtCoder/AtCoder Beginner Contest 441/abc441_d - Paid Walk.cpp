#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int to,w;};
vector<node> mp[MAX];
int tag[MAX];
int l,s,t;
void dfs(int x,int len,int now)
{
	if(now>t) return;
	if(len==l)
	{
		if(s<=now) tag[x]=1;
		return;
	}
	for(auto &it:mp[x]) dfs(it.to,len+1,now+it.w);
}
int main()
{
	int n,m,i,a,b,c;
	scanf("%d%d%d%d%d",&n,&m,&l,&s,&t);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		tag[i]=0;
	}
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
	}
	dfs(1,0,0);
	vector<int> res;
	for(i=1;i<=n;i++)
	{
		if(tag[i]) res.push_back(i);
	}
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	return 0;
}
