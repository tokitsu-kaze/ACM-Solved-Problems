#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
int scc,top,tot;
vector<int> mp[MAX];
int low[MAX],dfn[MAX],belong[MAX];
int stk[MAX],flag[MAX];
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		low[i]=0;
		dfn[i]=0;
		stk[i]=0;
		flag[i]=0;
	}
	scc=top=tot=0;
}
void tarjan(int x)
{
	int to,i,temp;
	stk[top++]=x;
	flag[x]=1;
	low[x]=dfn[x]=++tot;
	for(i=0;i<mp[x].size();i++)
	{
		to=mp[x][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if(flag[to]) low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x])
	{
		scc++;
		do
		{
			temp=stk[--top];
			flag[temp]=0;
			belong[temp]=scc;
		}while(temp!=x);
	}
}
int tag[MAX];
void dfs(int x)
{
	if(tag[x]) return ;
	tag[x]=1;
	for(auto to:mp[x])
	{
		dfs(to);
	}
}
int in[MAX];
int main()
{
	int n,m,s,a,b,i,j,ans;
	while(~scanf("%d%d%d",&n,&m,&s))
	{
		init(n);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
		}
		mem(tag,0);
		dfs(s);
		for(i=1;i<=n;i++)
		{
			if(tag[i]) continue;
			if(!dfn[i]) tarjan(i);
		}
		mem(in,0);
		for(i=1;i<=n;i++)
		{
			if(!belong[i]) continue;
			for(j=0;j<sz(mp[i]);j++)
			{
				if(belong[i]!=belong[mp[i][j]]) in[belong[mp[i][j]]]++;
			}
		} 
		ans=0;
		for(i=1;i<=scc;i++)
		{
			ans+=(!in[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
