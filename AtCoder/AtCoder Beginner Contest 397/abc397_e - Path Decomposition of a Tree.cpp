#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int k,cnt,tmp[MAX];
vector<int> mp[MAX];
void dfs(int x,int fa)
{
	if(cnt==-1) return;
	tmp[x]=0;
	int now[3],tot=0;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		if(tmp[to])
		{
			if(tot==2)
			{
				cnt=-1;
				return;
			}
			now[tot++]=tmp[to];
		}
	}
	if(tot==1)
	{
		if(now[0]+1==k)
		{
			cnt++;
			tmp[x]=0;
		}
		else tmp[x]=now[0]+1;
	}
	else if(tot==2)
	{
		if(now[0]+1+now[1]==k)
		{
			cnt++;
			tmp[x]=0;
		}
		else cnt=-1;
	}
	else tmp[x]=1;
}
int main()
{
	int n,i,a,b,tar;
	scanf("%d%d",&n,&k);
	tar=n;
	n*=k;
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	if(k==1) return 0*puts("Yes");
	cnt=0;
	dfs(1,0);
	if(cnt==tar) puts("Yes");
	else puts("No");
	return 0;
}
