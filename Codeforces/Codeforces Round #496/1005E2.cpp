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
const int MAX=4e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
struct Fenwick_Tree
{
	int bit[MAX];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void insert(int x,int v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	int get(int x)
	{
		int res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	int query(int l,int r)
	{
		return get(r)-get(l-1);
	}
}t;
int bit[MAX],a[MAX];
int main()
{
	int n,m,i;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		auto gao=[&](int mm)
		{
			ll res;
			int f[]={-1,1};
			bit[0]=0;
			for(i=1;i<=n;i++) bit[i]=bit[i-1]+f[a[i]<=mm];
			t.init(2*n+1);
			t.insert(n+1,1);
			res=0;
			for(i=1;i<=n;i++)
			{
				res+=t.get(bit[i]+n+1);
				t.insert(bit[i]+n+1,1);
			}
			return res;
		};
		printf("%lld\n",gao(m)-gao(m-1));
	}
	return 0;
}