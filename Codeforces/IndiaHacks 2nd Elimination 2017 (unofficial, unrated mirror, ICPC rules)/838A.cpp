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
char mp[5010][5010];
int a[5010][5010];
int main()
{
	int n,m,i,j,k,ans,x,y;
	while(~scanf("%d%d",&n,&m))
	{
		mem(a,0);
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			scanf("%s",mp[i]+1);
		}
		for(i=1;i<=2*max(n,m);i++)
		{
			for(j=1;j<=2*max(n,m);j++)
			{
				a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(mp[i][j]=='1');
			}
		}
		ans=INF;
		for(k=2;k<=max(n,m);k++)
		{
			int s=0;
			for(i=k;i-k<=n;i+=k)
			{
				for(j=k;j-k<=m;j+=k)
				{
					x=i-k;
					y=j-k;
					s+=min(a[i][j]-a[x][j]-a[i][y]+a[x][y],k*k-(a[i][j]-a[x][j]-a[i][y]+a[x][y]));
	//				cout<<a[i][j]-a[x][j]-a[i][y]+a[x][y]<<endl;
					if(s>=ans) goto end;
				}
			}
			ans=min(ans,s);
	//		cout<<ans<<endl;
			end:;
		}	
		printf("%d\n",ans);
	}
	return 0;
}