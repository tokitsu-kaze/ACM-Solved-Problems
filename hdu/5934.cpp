////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-14 20:46:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5934
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:7348KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e3+10;
const ll mod=1e9+7;
int scc,top,tot;
vector<int> mp[MAX];
int low[MAX],dfn[MAX],belong[MAX],degree[MAX];
int stk[MAX],flag[MAX];
ll x[MAX],y[MAX],r[MAX],v[MAX],ans[MAX];
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
		ans[i]=INF;
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
			ans[scc]=min(ans[scc],v[temp]);
		}while(temp!=x);
	}
}
int main()
{
	int t,cas=1,i,j,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld%lld",&x[i],&y[i],&r[i],&v[i]);
		}
		init(n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=r[j]*r[j]) mp[j].pb(i);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i);
		}
//		cout<<scc<<endl;
		mem(degree,0);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<sz(mp[i]);j++)
			{
				if(belong[i]!=belong[mp[i][j]])
				{
					degree[belong[mp[i][j]]]++;
				}
			}
		}
		ll res=0;
		for(i=1;i<=scc;i++)
		{
			if(!degree[i]) res+=ans[i];
		}
		printf("Case #%d: %lld\n",cas++,res);
	}
	return 0;
}