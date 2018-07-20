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
const int MAX=5e4+10;
const ll mod=1e9+7;
int main()
{
	int x,l,r,n,i,ans,a;
	while(~scanf("%d%d%d",&x,&l,&r))
	{
		scanf("%d",&n);
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a>l&&a<r) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}