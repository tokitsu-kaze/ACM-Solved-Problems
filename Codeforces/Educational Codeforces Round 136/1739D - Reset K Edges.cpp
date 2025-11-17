#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int mxdep[MAX],cnt,limt,k;
void dfs(int x,int h)
{
	mxdep[x]=h;
	for(auto &to:mp[x])
	{
		dfs(to,h+1);
		if(mxdep[to]-h==limt && x!=1) cnt++;
		else mxdep[x]=max(mxdep[x],mxdep[to]);
	}
}
int ck(int x)
{
	limt=x;
	cnt=0;
	dfs(1,0);
	return cnt<=k;
}
int main()
{
	int T,n,i,fa,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&fa);
			mp[fa].push_back(i);
		}
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
