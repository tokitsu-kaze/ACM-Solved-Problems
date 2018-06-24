////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-01-12 16:57:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5129
////Problem Title: 
////Run result: Accept
////Run time:561MS
////Run memory:48224KB
//////////////////System Comment End//////////////////
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
const int MAX=3e5+10;
const ll mod=1e9+7;
struct AC_Automaton
{
	int next[MAX][26],fail[MAX],pre[MAX];
	int root,tot;
	int newnode()
	{
		int i;
		mem(next[tot],0);
		fail[tot]=0;
		pre[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s)
	{
		int len,now,i,fa;
		len=strlen(s);
		now=root;
		fa=root;
		for(i=0;i<len;i++)
		{
			int t=s[i]-'a';
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
			pre[now]=fa;
			fa=now;
		}
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
	vector<int> mp[MAX];
	void build_tree()
	{
		int i;
		for(i=0;i<tot;i++) mp[i].clear();
		for(i=1;i<tot;i++)
		{
			mp[fail[i]].pb(i);
		}
	}
	ll res;
	int sz[MAX];
	void dfs(int x)
	{
		int i,to;
		sz[x]=1;
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			dfs(to);
			sz[x]+=sz[to];
		}
	}
	void work()
	{
		res=0;
		dfs(0);
		int i,j,k;
		for(i=1;i<tot;i++)
		{
			if(fail[i]==root) continue;
			j=i;
			k=fail[i];
			while(k)
			{
				j=pre[j];
				k=pre[k];
			}
			res+=sz[j]-1;
		}
		printf("%lld\n",1LL*(tot-1)*(tot-1)-res);
	} 
}ac;
int main()
{
	int n,i;
	char s[33];
	while(~scanf("%d",&n)&&n)
	{
		ac.init();
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			ac.insert(s);
		}
		ac.setfail();
		ac.build_tree();
		ac.work();
	}
	return 0;
}
/*
2
ab
aab
*/