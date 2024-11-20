#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2000+10;
int dp[MAX][MAX],a[MAX];
ll bit[MAX];
int main()
{
	int t,n,i,j,len,l,r,x,y;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			bit[i]=bit[i-1]+a[i];
		}
/*		memset(dp,0,sizeof dp);
		for(i=1;i<=n;i++) dp[i][i]=0;
		ans=0;
		for(len=2;len<=n;len++)
		{
			for(l=1;l+len-1<=n;l++)
			{
				r=l+len-1;
				dp[l][r]=r-l;
				for(x=l;x<=r;x++)
				{
					for(y=x-1;y<r;y++)
					{
						if(bit[x-1]-bit[l-1]!=bit[r]-bit[y]) continue;
						dp[l][r]=min(dp[l][r],dp[x][y]+(x-l-1)+(r-y-1));
					}
				}
				ans+=dp[l][r];
			}
		}*/
		
//		bit[x-1]+bit[y]==bit[l-1]+bit[r]
//		dp[x][y]+(x-y-1)+(r-l-1)
		map<ll,int> mp;
		for(i=1;i<=n;i++)
		{
			dp[i][i]=0;
			mp[bit[i-1]+bit[i]]=dp[i][i]+(i-i-1);
			dp[i][i-1]=0;
			mp[bit[i-1]+bit[i-1]]=dp[i][i-1]+(i-(i-1)-1);
		}
		ans=0;
		for(len=2;len<=n;len++)
		{
			for(l=1;l+len-1<=n;l++)
			{
				r=l+len-1;
				if(!mp.count(bit[l-1]+bit[r])) mp[bit[l-1]+bit[r]]=INF;
				dp[l][r]=min(r-l,mp[bit[l-1]+bit[r]]+r-l-1);
				mp[bit[l-1]+bit[r]]=min(mp[bit[l-1]+bit[r]],dp[l][r]+l-r-1);
				ans+=dp[l][r];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

