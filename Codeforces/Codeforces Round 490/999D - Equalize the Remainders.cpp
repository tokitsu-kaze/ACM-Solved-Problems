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
ll a[MAX];
queue<int> res[MAX];
PLL st[MAX];
int n,k,tot;
ll ans;
void gao()
{
	int i,j,sz;
	ll tmp;
	for(i=0;i<k;i++)
	{
		while(sz(res[i])>n/k)
		{
			st[tot++]=MP(res[i].front(),i);
			res[i].pop();
		}
		if(sz(res[i])==n/k) continue;
		sz=sz(res[i]);
		for(j=0;tot&&j<n/k-sz;j++)
		{
			res[i].push(st[tot-1].fi);
			tmp=i-st[tot-1].se;
			if(tmp<0) tmp+=k;
			a[st[tot-1].fi]+=tmp;
			ans+=tmp;
			tot--;
		}
	}
}
int main()
{
	int i,j;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=0;i<k;i++)
		{
			while(!res[i].empty()) res[i].pop();
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			res[a[i]%k].push(i);
		}
		ans=0;
		tot=0;
		gao();
		gao();
		printf("%lld\n",ans);
		for(i=1;i<=n;i++) printf("%lld%c",a[i]," \n"[i==n]);
	}
	return 0;
}
/*
8 4
0 0 0 0 2 2 2 2
8 4
1 1 1 1 3 3 3 3
6 2
0 0 1 1 1 1
*/
