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
int a[1111];
int main()
{
	int t,n,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<n-1;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}