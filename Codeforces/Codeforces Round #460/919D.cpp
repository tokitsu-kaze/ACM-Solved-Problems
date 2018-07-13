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
const int MAX=3e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
char s[MAX];
int in[MAX],flag[MAX],res[MAX][26],tag,ans;
void dfs(int x)
{
	int i,j,to;
	if(flag[x]) return;
	flag[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		dfs(to);
		for(j=0;j<26;j++)
		{
			res[x][j]=max(res[x][j],res[to][j]);
		}
	}
	res[x][s[x]-'a']++;
}
void dfs2(int x)
{
	int i,to;
	tag|=(flag[x]==1);
	if(flag[x]) return;
	flag[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		dfs2(to);
	}
	flag[x]=-1;
}
int main()
{
	int n,m,a,b,i,j,tot;
	while(~scanf("%d%d",&n,&m))
	{
		scanf("%s",s+1);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			in[i]=0;
			flag[i]=0;
			mem(res[i],0);
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			in[b]++;
		}
		tag=0;
		for(i=1;i<=n;i++)
		{
			dfs2(i);
			if(tag)
			{
				puts("-1");
				goto end;
			}
		}
		mem(flag,0);
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(!in[i]&&!flag[i])
			{
				dfs(i);
				for(j=0;j<26;j++) ans=max(ans,res[i][j]);
			}
		}
		printf("%d\n",ans);
		end:;
	}
	return 0;
}