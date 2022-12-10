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
const int MAX=2e5+10;
const ll mod=1e9;
struct node
{
	ll h,d;
	friend bool operator <(node a,node b)
	{
		return a.h-a.d>b.h-b.d;
	}
	void input()
	{
		scanf("%lld%lld",&h,&d);
	}
}a[MAX];
int main()
{
	int i,n,x,y;
	ll ans,now,tmp;
	while(~scanf("%d%d%d",&n,&x,&y))
	{
		for(i=0;i<n;i++) a[i].input();
		sort(a,a+n);
		ans=0;
		for(i=0;i<n;i++) ans+=a[i].d;
		if(y==0) goto end;
		y--;
		tmp=0;
		for(i=0;i<n;i++)
		{
			if(i<y&&a[i].h>a[i].d) ans+=a[i].h-a[i].d;
			if(i==y&&a[i].h>a[i].d) tmp=a[i].h-a[i].d;
		}
		now=ans;
		for(i=0;i<n;i++)
		{
			if(i<y&&a[i].h>a[i].d) ans=max(ans,now+((1LL<<x)-1)*a[i].h+tmp);
			else ans=max(ans,now+(1LL<<x)*a[i].h-a[i].d);
		}
		end:;
		printf("%lld\n",ans);
	}
	return 0;
}