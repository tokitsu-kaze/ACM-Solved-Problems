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
const int MAX=3e5+10;
const ll mod=1e9+7;
int main()
{
	int k,n,m,ans,i,j;
	char mp[111][111];
	freopen("class.in","r",stdin);
	freopen("class.out","w",stdout);
	while(~scanf("%d%d%d",&k,&n,&m))
	{
		ans=min(min(n,m),(k+1)/2);
		mem(mp,'.');
		mp[0][0]='#';
		k--;
		i=j=1;
		while(k&&i<n&&j<m)
		{
			if(i<m) mp[0][i++]='#';
			k--;
			if(k<=0) break;
			if(j<n) mp[j++][0]='#';
			k--;
		}
		for(i=0;i<n&&k;i++)
		{
			for(j=0;j<m&&k;j++)
			{
				if(mp[i][j]=='.')
				{
					mp[i][j]='#';
					k--;
				}
			}
		}
		printf("%d\n",ans);
		for(i=0;i<n;i++)
		{
			mp[i][m]='\0';
			puts(mp[i]);
		}
	}
	return 0;
}