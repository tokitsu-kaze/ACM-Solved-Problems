#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int main()
{
	int n,i,j,tmp,a[2011];
	while(~scanf("%d",&n))
	{
		a[0]=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
		PII ans;
		tmp=-INF;
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				if(a[j]-a[i-1]>tmp)
				{
					tmp=a[j]-a[i-1];
					ans=MP(i,j);
				}
			}
		}
		printf("From=%d,To=%d\n",ans.fi,ans.se);
		printf("MaxSum=%d\n",tmp);
	}
	return 0;
}
