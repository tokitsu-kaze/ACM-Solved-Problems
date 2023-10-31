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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;


	int pre[MAX],cnt[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			cnt[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	void merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			cnt[rb]+=cnt[ra];
			cnt[ra]=0;
		}
	}

vector<int> mp[MAX],res[MAX];
int k,flag,belong[MAX];
void dfs(int x,int fa)
{
	int tag=0;
	for(auto to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		if(tag) continue;
		if(cnt[find(to)]!=k)
		{
			merge(to,x);
			if(cnt[find(x)]==k) tag=1;
			else if(cnt[find(x)]>k) flag=1;
		}
	}
	if(cnt[find(x)]>k) flag=1;
}
int main()
{
	int t,n,i,j,a,b,tot;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		init(n);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			res[i].clear();
			belong[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		flag=0;
		dfs(1,-1);
		tot=0;
		for(i=1;i<=n;i++)
		{
			int tmp=find(i);
			if(!belong[tmp]) belong[tmp]=++tot;
			res[belong[tmp]].pb(i);
		}
		for(i=1;i<=tot;i++)
		{
			if(sz(res[i])!=k) flag=1;
		}
		if(flag)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(i=1;i<=tot;i++)
		{
			for(j=0;j<sz(res[i]);j++) printf("%d%c",res[i][j]," \n"[j==sz(res[i])-1]);
		}
	}
	return 0;
}
