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
const double eps=1e-6;
const int MAX=2e3+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,i,j,g,ans,cnt;
	while(~scanf("%d",&n))
	{
		g=0;
		cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			g=__gcd(g,a[i]);
			if(a[i]==1) cnt++;
		}
		if(cnt)
		{
			printf("%d\n",n-cnt);
			continue;
		} 
		if(g!=1)
		{
			puts("-1");
			continue;
		}
		ans=INF;
		for(i=0;i<n;i++)
		{
			g=a[i];
			for(j=i+1;j<n;j++)
			{
				g=__gcd(g,a[j]);
				if(g==1) ans=min(ans,j-i);
			}
		}
		printf("%d\n",ans+n-1);
	}
	return 0;
}