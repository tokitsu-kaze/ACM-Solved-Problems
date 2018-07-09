#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/***************************************  head  **********************************************/
vector<PII > mp[MAX];
int mx,rt,fa[MAX],dep[MAX],flag[MAX];
void dfs(int x,int pre)
{
	fa[x]=pre;
	if(pre==-1) dep[x]=0;
	for(auto to:mp[x])
	{
		if(to.fi==pre) continue;
		if(flag[to.fi]) continue;
		dep[to.fi]=dep[x]+to.se;
		dfs(to.fi,x);
	}
	if(mx<dep[x])
	{
		rt=x;
		mx=dep[x];
	}
}
int dq[MAX],l,r;
int main()
{
	int n,k,i,j,a,b,w,ans;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		mem(flag,0);
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&w);
			mp[a].pb(MP(b,w));
			mp[b].pb(MP(a,w));
		}
		mx=0;
		rt=1;
		dfs(rt,-1);
		mx=0;
		dfs(rt,-1);
		vector<PII > res;
		while(~rt)
		{
			res.pb(MP(rt,dep[rt]));
			flag[rt]=1;
			rt=fa[rt];
		}
		reverse(all(res));
		VI len;
		for(auto it:res)
		{
			mx=0;
			dfs(it.fi,-1);
			len.pb(mx);
	//		cout<<it.fi<<" "<<it.se<<endl;
		}
		l=r=0;
		k=min(k,sz(res));
		ans=INF;
		for(i=0,j=0;i+k-1<sz(res);i++)
		{
			while(i+j<k)
			{
				while(r-l&&len[dq[r-1]]<len[j]) r--;
				dq[r++]=j++;
			}
			while(r-l&&dq[l]<i) l++;
			ans=min(ans,max({res[i].se,res[sz(res)-1].se-res[i+k-1].se,len[dq[l]]}));
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
8 6
1 4 10
2 4 1
3 4 1
4 5 10
5 6 10
3 7 1
2 8 1
*/
