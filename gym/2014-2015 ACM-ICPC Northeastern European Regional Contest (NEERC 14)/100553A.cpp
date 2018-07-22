#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e3+10;
const ll mod=1e9+7;
int main()
{
	int n,m,ans,i;
	freopen("alter.in","r",stdin);
	freopen("alter.out","w",stdout);
	while(~scanf("%d%d",&n,&m))
	{
		ans=n/2+m/2;
		printf("%d\n",ans);
		for(i=2;i<=n;i+=2)
		{
			printf("%d %d %d %d\n",i,1,i,m);
		}
		for(i=2;i<=m;i+=2)
		{
			printf("%d %d %d %d\n",1,i,n,i);
		}
	}
	return 0;
}