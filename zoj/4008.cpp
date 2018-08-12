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
const double eps=1e-8;
const int MAX=4e5+10;
const ll mod=1e9+7;
struct node
{
	int a,b,tag;
	void input(int f)
	{
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		tag=f;
	}
	friend bool operator <(node a,node b)
	{
		if(a.a==b.a) return a.tag<b.tag;
		return a.a>b.a;
	}
}a[MAX];
struct Fenwick_Tree
{
	int bit[MAX];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void update(int x,int v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	int operator [](int x)
	{
		int res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
}tr;
int ans[MAX];
int main()
{
	int t,n,q,i,tot;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		tot=0;
		tr.init(n);
		for(i=0;i<n-1;i++) a[tot++].input(0);
		for(i=1;i<=q;i++) a[tot++].input(i);
		sort(a,a+tot);
		for(i=0;i<tot;i++)
		{
			if(a[i].tag) ans[a[i].tag]=a[i].b-a[i].a+1-tr[a[i].b];
			else tr.update(a[i].b,1);
		}
		for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
	return 0;
}