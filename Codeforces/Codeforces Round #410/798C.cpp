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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,i,ans,g;
	while(~scanf("%d",&n))
	{
		g=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			g=__gcd(g,a[i]);
		}
		if(g>1)
		{
			puts("YES");
			puts("0");
			continue;
		}
		ans=0;
		for(i=0;i<n-1;i++)
		{
			if(a[i]%2&&a[i+1]%2)
			{
				ans++;
				a[i]=a[i+1]=2;
			}
		}
		for(i=0;i<n-1;i++)
		{
			if(a[i]%2||a[i+1]%2)
			{
				ans+=2;
				a[i]=a[i+1]=2;
			}
		}
		puts("YES");
		printf("%d\n",ans);
	}
	return 0;
}