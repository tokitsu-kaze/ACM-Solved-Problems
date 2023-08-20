////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-23 16:37:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6165
////Problem Title: 
////Run result: Accept
////Run time:202MS
////Run memory:2040KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e3+10;
const ll mod=1e9+7;
int n,top,k,s;
vector<int> mp[MAX],mp1[MAX];
int low[MAX],dfn[MAX],belong[MAX],cnt2[MAX];
int sstack[MAX],flag[MAX];
int tag;
int degree[MAX];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		mp1[i].clear();
		degree[i]=-1;
	}
	mem(low,0);
	mem(dfn,0);
	mem(sstack,0);
	mem(flag,0);
	top=k=0;
	mem(cnt2,0);
}
void tarjan(int now)
{
	int to,i,temp;
	sstack[top++]=now;
	flag[now]=1;
	low[now]=dfn[now]=++k;
	for(i=0;i<mp[now].size();i++)
	{
		to=mp[now][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}
		else if(flag[to]) low[now]=min(low[now],dfn[to]);
	}
	if(low[now]==dfn[now])
	{
		int sc=sstack[top-1];
		s++;
		do
		{
			s--;
			temp=sstack[--top];
			flag[temp]=0;
			belong[temp]=sc;
			cnt2[sc]++;
		}while(temp!=now);
	}
}
void build(int x)
{
	int i;
	if(degree[belong[x]]==-1) degree[belong[x]]=0;
	if(flag[x]) return;
	flag[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		int temp=belong[mp[x][i]];
		if(belong[x]!=belong[mp[x][i]])
		{
			mp1[belong[x]].pb(temp);
			if(degree[temp]==-1) degree[temp]=0;
			degree[temp]++;
		}
		build(mp[x][i]);
	}
}
int ans[MAX];
void dfs(int x)
{
	int i;
	for(i=0;i<sz(mp1[x]);i++)
	{
		ans[mp1[x][i]]=max(ans[mp1[x][i]],ans[x]+1);
		dfs(mp1[x][i]);
	}
}
int main()
{
	int a,b,m,i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
		}
		s=n;
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i);
		}
	//	cout<<s<<endl;
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			if(!flag[i]) build(i);
		}
		mem(ans,0);
		for(i=1;i<=n;i++)
		{
			if(degree[i]==0)
			{
	//			cout<<i<<endl;
				ans[i]=1;
				dfs(i);
				break;
			}
		}
		tag=0;
		for(i=1;i<=n;i++)
		{
	//		cout<<ans[i]<<endl;
			if(ans[i]==s) tag=1;
		}
		if(!tag) puts("Light my fire!");
		else puts("I love you my love and our love save us!");
	}
	return 0;
} 
/*
100
5 5
3 1
3 4
1 2
2 4
5 4

5 4
1 3
1 2
3 4
3 5

5 5
5 2
2 3
3 1
1 2
1 4

4 4
1 4
1 2
3 1
2 3

3 3
1 2
2 3
1 3

3 2
1 2
1 3
*/