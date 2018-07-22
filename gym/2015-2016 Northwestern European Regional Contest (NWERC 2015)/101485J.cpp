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
int ans[MAX],a[MAX];
void init()
{
	int i;
	mem(ans,0);
	for(i=0;i<=2000;i++)
	{
		if(!ans[(i^(i<<1)%256)]) ans[(i^(i<<1)%256)]=i;
	}
}
int main()
{
	init();
	int i,n,x;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[i]=ans[x];
		}
		for(i=0;i<n;i++)
		{
			if(i==n-1) printf("%d\n",a[i]);
			else printf("%d ",a[i]);
		}
	}
	return 0;
}