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
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int main()
{
	int n,m,i,j,a[111],cnt[111];
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=m;i++) scanf("%d",&a[i]);
		if(n>m)
		{
			puts("0");
			continue;
		}
		mem(cnt,0);
		for(i=1;i<=m;i++) cnt[a[i]]++;
		for(i=100;i;i--)
		{
			int now=0;
			for(j=1;j<=100;j++)
			{
				now+=cnt[j]/i;
			}
			if(now>=n)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}