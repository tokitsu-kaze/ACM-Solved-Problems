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
const int MAX=5e5+10;
const ll mod=1e9+7;
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
}tr;
int a[MAX],dp[MAX];
int main()
{
	int n,k,d,i,j;
	while(~scanf("%d%d%d",&n,&k,&d))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		tr.init(n);
		sort(a+1,a+1+n);
		mem(dp,0);
		for(i=k;i<=n;i++)
		{
			if(a[i]-a[1]<=d) dp[i]=1;
			else
			{
				j=lower_bound(a+1,a+1+n,a[i]-d)-a-1;
				if(i-k>=j) dp[i]=tr.query(j,i-k);
			}
			if(dp[i]) tr.insert(i,1);
		}
		dp[n]?puts("YES"):puts("NO");
	}
	return 0;
} 