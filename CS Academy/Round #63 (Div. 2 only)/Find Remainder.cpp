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
int a[MAX],b[MAX];
int main()
{
	int i,g,n,maxx,ans;
	while(~scanf("%d",&n))
	{
		g=0;
		maxx=0;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) scanf("%d",&b[i]),maxx=max(maxx,b[i]);
		if(maxx==0)
		{
			puts("1");
			goto end;
		}
		for(i=0;i<n;i++)
		{
			g=__gcd(g,a[i]-b[i]);
			if(b[i]>a[i])
			{
				puts("-1");
				goto end;
			}
		}
		if(g==0) g=maxx+1;
		for(i=0;i<n;i++)
		{
			if(a[i]%g!=b[i])
			{
				puts("-1");
				goto end;
			}
		}
		ans=INF;
		for(i=1;i<=sqrt(g);i++)
		{
			if(g%i==0)
			{
				if(i>maxx) ans=min(ans,i);
				if(g/i>maxx) ans=min(ans,g/i);
			}
		}
		printf("%d\n",ans);
		end:;
	}
	return 0;
}
