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
int main()
{
	int n,a,b,i,j,w[111],h[111],ans;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&w[i],&h[i]);
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(max(w[i],w[j])<=a&&h[i]+h[j]<=b)
				{
					ans=max(ans,w[i]*h[i]+w[j]*h[j]);
				}
				else if(max(h[i],h[j])<=a&&w[i]+w[j]<=b)
				{
					ans=max(ans,w[i]*h[i]+w[j]*h[j]);
				}
				else if(max(h[i],w[j])<=a&&w[i]+h[j]<=b)
				{
					ans=max(ans,w[i]*h[i]+w[j]*h[j]);
				}
				else if(max(w[i],h[j])<=a&&h[i]+w[j]<=b)
				{
					ans=max(ans,w[i]*h[i]+w[j]*h[j]);
				}
				else if(max(w[i],w[j])<=b&&h[i]+h[j]<=a)
				{
					ans=max(ans,w[i]*h[i]+w[j]*h[j]);
				}
				else if(max(h[i],h[j])<=b&&w[i]+w[j]<=a)
				{
					ans=max(ans,w[i]*h[i]+w[j]*h[j]);
				}
				else if(max(h[i],w[j])<=b&&w[i]+h[j]<=a)
				{
					ans=max(ans,w[i]*h[i]+w[j]*h[j]);
				}
				else if(max(w[i],h[j])<=b&&h[i]+w[j]<=a)
				{
					ans=max(ans,w[i]*h[i]+w[j]*h[j]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}