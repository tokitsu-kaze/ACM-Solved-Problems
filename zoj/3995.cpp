#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=5e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int path[2*MAX],deep[2*MAX],first[MAX],flag[MAX],tot;
int dp[2*MAX][28];
int deepmark[MAX];
void dfs(int x,int h)
{
	int i;
	flag[x]=1;
	path[++tot]=x;
	first[x]=tot;
	deep[tot]=h;
	deepmark[x]=h;
	for(i=0;i<mp[x].size();i++)
	{
		int to=mp[x][i];
		if(!flag[to])
		{
			dfs(to,h+1);
			path[++tot]=x;
			deep[tot]=h;
		}
	}
}
void ST(int n)
{
	int i,j,x,y;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=i;
	}
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			x=dp[i][j-1];
			y=dp[i+(1<<(j-1))][j-1];
			dp[i][j]=deep[x]<deep[y]?x:y;
		}
	}
}
int query(int l,int r)
{
	int len,x,y;
	len=(int)log2(r-l+1); 
	x=dp[l][len];
	y=dp[r-(1<<len)+1][len];
	return deep[x]<deep[y]?x:y;
}
int lca(int x,int y)
{
	int l,r,pos;
	l=first[x];
	r=first[y];
	if(l>r) swap(l,r);
	pos=query(l,r);
	return path[pos];
}
void work(int n)
{
	int i;
	tot=0;
	mem(flag,0);
	dfs(0,0);
	ST(2*n-1);
}
struct AC_Automaton
{
	int next[MAX][26],fail[MAX],cnt[MAX],tail[MAX];
	int root,tot;
	int newnode()
	{
		int i;
		tot++;
		mem(next[tot],0);
		fail[tot]=0;
		cnt[tot]=0;
		return tot;
	}
	void init()
	{
		tot=-1;
		root=newnode();
	}
	void insert(char *s,int x)
	{
		int len,now,i;
		len=strlen(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=s[i]-'a';
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
			cnt[now]++;
		}
		tail[x]=now;
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<26;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			for(i=0;i<26;i++)
			{
				if(next[now][i])
				{
					fail[next[now][i]]=next[fail[now]][i];
					q.push(next[now][i]);
				}
				else next[now][i]=next[fail[now]][i];
			}
		}
	}
	void build_tree()
	{
		int i;
		for(i=0;i<=tot;i++) mp[i].clear();
		for(i=1;i<=tot;i++)
		{
			mp[fail[i]].pb(i);
		}
		work(tot);
	}
	int query(int x,int y)
	{
		int res;
		res=lca(tail[x],tail[y]);
		return cnt[res];
	}
}ac;
char s[MAX];
int main()
{
	int n,i,q,x,y;
	while(~scanf("%d",&n))
	{
		ac.init();
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			ac.insert(s,i);
		}
		ac.setfail();
		ac.build_tree();
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&x,&y);
			int ans=ac.query(x,y);
			ans?printf("%d\n",ans):puts("N"); 
		}
	}
	return 0;
}