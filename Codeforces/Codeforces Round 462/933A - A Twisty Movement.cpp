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
const double eps=1e-4;
const int MAX=2e3+10;
const ll mod=1e9+7;
int x[MAX],y[MAX],b[MAX];
int main()
{
	int i,j,ans,n,a[MAX],now;
	while(~scanf("%d",&n))
	{
		x[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			x[i]=(a[i]==1);
			x[i]+=x[i-1];
		}
		y[n+1]=0;
		for(i=n;i>=1;i--)
		{
			y[i]=(a[i]==2);
			y[i]+=y[i+1];
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			now=0;
			mem(b,0x3f);
			for(j=i;j<=n;j++)
			{
				*upper_bound(b+i,b+j+1,-a[j])=-a[j];
				now=lower_bound(b+i,b+j+1,INF)-b-i;
				ans=max(ans,x[i-1]+y[j+1]+now);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}