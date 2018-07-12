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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int ans[MAX],a[MAX];
struct node
{
	int l,x,id;
	void input(int i)
	{
		id=i;
		scanf("%d%d",&l,&x);
	}
	friend bool operator <(node a,node b)
	{
		return a.l<b.l;
	}
}q[MAX];
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
struct Base
{
	#define type int
	#define mx 31
	type d[mx+3],p[mx+3],cnt;
	Base()
	{
		memset(d,0,sizeof(d));
		memset(p,0,sizeof(p));
		cnt=0;
	}
	bool insert(type x)
	{
		int i;
		for(i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				cnt++;
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		return x>0;
	}
	void work(node t)
	{
		int i,x=t.x;
		for(i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			x^=d[i];
		}
		ans[t.id]=(x?0:pow2(2,t.l-cnt));
	}
}; 
int main()
{
	int n,m,i,j;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++) q[i].input(i);
		sort(q+1,q+1+m);
		Base lb;
		j=1;
		for(i=1;i<=n;i++)
		{
			lb.insert(a[i]);
			while(q[j].l==i)
			{
				lb.work(q[j]);
				j++;
			}
		}
		for(i=1;i<=m;i++) printf("%d\n",ans[i]);
	}
	return 0;
}