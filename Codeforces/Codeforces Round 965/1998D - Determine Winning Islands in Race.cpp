#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<int> mp[MAX];
int dis[MAX];
void bfs(int s)
{
	int x;
	queue<int> q;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto &to:mp[x])
		{
			if(dis[to]>dis[x]+1)
			{
				dis[to]=dis[x]+1;
				q.push(to);
			}
		}
	}
}
int bit[MAX],a[MAX],b[MAX];
char ans[MAX];
int main()
{
	int t,n,m,i,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++) mp[i].push_back(i+1);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			mp[a[i]].push_back(b[i]);
		}
		for(i=1;i<=n;i++) dis[i]=INF;
		bfs(1);
		for(i=0;i<=n+1;i++) bit[i]=0;
		for(i=1;i<=m;i++)
		{
			l=a[i]+1;
			r=b[i]-dis[a[i]]-1;
			if(l>r) continue;
			bit[l]--;
			bit[r]++;
		}
		for(i=1;i<=n;i++)
		{
			bit[i]+=bit[i-1];
			ans[i]=(bit[i]>=0)+'0';
		}
		ans[n]='\0';
		puts(ans+1);
	}
	return 0;
}
