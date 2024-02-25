#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<int> mp[MAX];
void bfs(int s,int *dis)
{
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int x=q.front();
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
int disx[MAX],disy[MAX];
int flag[MAX],in_cir[MAX];
vector<int> cir;
int st[MAX],top;
void dfs(int x,int fa)
{
	flag[x]=2;
	st[top++]=x;
	for(auto &to:mp[x])
	{
		if(cir.size()) return;
		if(to==fa) continue;
		if(flag[to]==2)
		{
			while(top>0)
			{
				cir.push_back(st[--top]);
				if(cir.back()==to) break;
			}
			return;
		}
		else dfs(to,x);
	}
	top--;
	flag[x]=1;
}
int main()
{
	int t,n,x,y,i,a,b,ok,pos,mn;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			disx[i]=disy[i]=0x3f;
			flag[i]=in_cir[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		bfs(x,disx);
		bfs(y,disy);
		cir.clear();
		top=0;
		dfs(1,0);
		ok=0;
		mn=INF;
		for(auto &it:cir)
		{
	//		printf("%d ",it);
			in_cir[it]=1;
			if(disy[it]<mn)
			{
				mn=disy[it];
				pos=it;
			}
		}
		if(in_cir[y]) ok=1;
		if(disy[pos]<disx[pos]) ok=1;
		if(x==y) ok=0;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
