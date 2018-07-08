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
const int MAX=2e4+10;
const ll mod=1e9+7;
int bit[MAX],a[MAX];
int main()
{
	int n,i,j,ans,zr;
	while(~scanf("%d",&n))
	{
		mem(bit,0);
		ans=0;
		zr=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			bit[a[i]]++;
			if(!a[i]) zr++;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(!a[i]||!a[j]) continue;
				ans+=bit[a[i]+a[j]];
			}
		}
		if(zr>=2)
		{
			for(i=1;i<=5000;i++)
			{
				if(bit[i]>=2) ans+=bit[i]*(bit[i]-1)/2*zr;
			}
			if(zr>=3) ans+=zr*(zr-1)*(zr-2)/6;
		}
		printf("%d\n",ans);
	}
	return 0;
}