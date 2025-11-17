#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
int a[MAX],b[MAX],c[MAX],cnt[MAX][2];
ll ans;
void dfs(int x,int fa,int mn)
{
	mn=min(mn,a[x]);
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,mn);
		cnt[x][0]+=cnt[to][0];
		cnt[x][1]+=cnt[to][1];
	}
	if(b[x]!=c[x]) cnt[x][b[x]]++;
	int tmp=min(cnt[x][0],cnt[x][1]);
	ans+=2LL*mn*tmp;
	cnt[x][0]-=tmp;
	cnt[x][1]-=tmp;
}
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		mp[i].clear();
		cnt[i][0]=cnt[i][1]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	ans=0;
	dfs(1,0,INF);
	if(cnt[1][0]!=0 || cnt[1][1]!=0) ans=-1;
	printf("%lld\n",ans);
	return 0;
}
