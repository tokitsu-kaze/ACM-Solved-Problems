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
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
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
int v[MAX],id[MAX];
int main()
{
	int n,x,y,i;
	ll ans;
	while(~scanf("%d%d%d",&n,&x,&y))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			id[i]=i;
		}
		sort(id+1,id+1+n,[](int a,int b){return v[a]==v[b]?a<b:v[a]<v[b];});
		tr.init(n);
		ans=0;
		for(i=n;i;i--)
		{
			ans+=tr.get(id[i]);
			tr.insert(id[i],1);
		}
		printf("%lld\n",min(x,y)*ans);
	}
	return 0;
}
