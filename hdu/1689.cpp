////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-07 11:09:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1689
////Problem Title: 
////Run result: Accept
////Run time:592MS
////Run memory:2268KB
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
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int flag[MAX][2];
int bfs(int x)
{
	int to,i;
	PII t;
	queue<PII> q;
	mem(flag,0);
	flag[x][1]=1;
	q.push(MP(x,1));
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<sz(mp[t.fi]);i++)
		{
			to=mp[t.fi][i];
			if(to==x&&(t.se&1)) return t.se;
			if(flag[to][(t.se+1)&1]) continue;
			flag[to][(t.se+1)&1]=1;
			q.push(MP(to,t.se+1));
		}
	}
	return INF;
}
int main()
{
	int t,cas=1,i,n,m,a,b,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) mp[i].clear();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		ans=INF;
		for(i=1;i<=n;i++) ans=min(ans,bfs(i));
		if(ans==INF) printf("Case %d: Poor JYY.\n",cas++);
		else printf("Case %d: JYY has to use %d balls.\n",cas++,ans);
	}
	return 0;
}