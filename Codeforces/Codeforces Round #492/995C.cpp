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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	ll a,b,p;
	void input(ll i)
	{
		scanf("%lld%lld",&a,&b);
		p=i;
	}
	friend bool operator <(node a,node b)
	{
		return a.a*a.a+a.b*a.b<b.a*b.a+b.b*b.b;
	}
}a[MAX];
int ans[MAX];
ll limt=2250000000000LL;
ll get(ll x,ll y)
{
	return x*x+y*y;
}
int main()
{
	ll i,n,x,y,sx,sy;
	while(~scanf("%lld",&n))
	{
		for(i=1;i<=n;i++) a[i].input(i);
		sort(a+1,a+1+n);
		x=y=0;
		sx=sy=0;
		for(i=1;i<=n;i++)
		{
			sx+=a[i].a;
			sy+=a[i].b; 
			if(get(x+a[i].a,y+a[i].b)<=get(x,y))
			{
				x+=a[i].a;
				y+=a[i].b;
				ans[a[i].p]=1;
			}
			else
			{
				x-=a[i].a;
				y-=a[i].b;
				ans[a[i].p]=-1;
			}
		}
		while(get(x,y)>limt)
		{
			for(i=n;i;i--)
			{
				if(ans[a[i].p]==-1&&get(x+2*a[i].a,y+2*a[i].b)<=limt)
				{
					x+=2*a[i].a;
					y+=2*a[i].b;
					ans[a[i].p]=1;
				}
				else if(ans[a[i].p]==1&&get(x-2*a[i].a,y-2*a[i].b)<=limt)
				{
					x-=2*a[i].a;
					y-=2*a[i].b;
					ans[a[i].p]=-1;
				}
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}

