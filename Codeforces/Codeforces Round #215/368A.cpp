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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,d,m,a[111],i,ans;
	while(~scanf("%d%d",&n,&d))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&m);
		sort(a,a+n);
		ans=0;
		for(i=0;i<min(n,m);i++)
		{
			ans+=a[i];
		}
		if(m>n) ans-=(m-n)*d;
		printf("%d\n",ans);
	}
	return 0;
}