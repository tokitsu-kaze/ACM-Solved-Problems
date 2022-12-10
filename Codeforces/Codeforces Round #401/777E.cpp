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
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int a,b,c;
	void in()
	{
		scanf("%d%d%d",&a,&b,&c);
	}
	friend bool operator<(node a,node b)
	{
		if(a.b==b.b)
		{
			if(a.a==b.a) return a.c>b.c;
			return a.a>b.a;
		}
		else return a.b>b.b;
	}
}a[MAX],s[MAX];
bool check(node x,node y)
{
	if(x.b<=y.b&&x.b>y.a) return 1;
	return 0;
}
int main()
{
	int n,i,top;
	ll now,ans;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++) a[i].in();
		sort(a,a+n);
		top=0;
		ans=now=0;
		for(i=0;i<n;i++)
		{
			if(!top) s[top++]=a[i],now+=a[i].c;
			else
			{
				while(top&&!check(a[i],s[top-1])) now-=s[top-1].c,top--;
				s[top++]=a[i],now+=a[i].c;
			}
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}