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
const double eps=1e-4;
const int MAX=4e5+10;
const ll mod=998244353;
int n,d,k,tot,in[MAX],h[MAX];
vector<PII > res;
void dfs(int x)
{
	while(1)
	{
		if(h[x]+1>d) return;
		if(in[x]+1>k) return;
		if(tot==n) return;
		tot++;
		in[x]++;
		in[tot]++;
		h[tot]=h[x]+1;
		res.pb(MP(x,tot));
		dfs(tot);
	}
}
int main()
{
	int i,j,flag;
	while(~scanf("%d%d%d",&n,&d,&k))
	{
		res.clear();
		mem(in,0);
		mem(h,0);
		d++;
		tot=d;
		if(d>n)
		{
			puts("NO");
			continue;
		}
		for(i=1;i<d;i++)
		{
			res.pb(MP(i,i+1));
			in[i]++;
			in[i+1]++;
			h[i]=max(d-i+1,i);
			h[i+1]=max(d-i,i+1);
		}
		for(i=1;i<=tot;i++) dfs(i);
		flag=0;
		for(i=1;i<=n;i++)
		{
			if(in[i]>k||h[i]>d) flag=1;
		}
		if(tot!=n) flag=1;
		if(flag)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		assert(sz(res)==n-1);
		for(auto it:res) printf("%d %d\n",it.fi,it.se);
	}
	return 0;
} 
