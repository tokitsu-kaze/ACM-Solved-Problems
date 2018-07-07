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
	int n,h,i,ans,maxx;
	while(~scanf("%d%d",&n,&h))
	{
		maxx=-1;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			maxx=max(maxx,a[i]);
		}
		sort(a,a+n);
		sort(b,b+n);
		ans=0;
		for(i=n-1;i>=0&&h>0;i--)
		{
			if(b[i]>=maxx)
			{
				h-=b[i];
				ans++;
			}
			else break;
		}
		h=max(0,h);
		printf("%d\n",ans+(h+a[n-1]-1)/a[n-1]);
	}
	return 0;
}
