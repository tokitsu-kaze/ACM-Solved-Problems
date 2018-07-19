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
const int MAX=1e3+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,a[111],ans,cnt;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			cnt=0;
			for(j=1;j<i;j++)
			{
				if(a[j]) cnt++;
			}
			for(j=i+1;j<=n;j++)
			{
				if(!a[j]) cnt++;
			}
			ans=max(ans,n-cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}