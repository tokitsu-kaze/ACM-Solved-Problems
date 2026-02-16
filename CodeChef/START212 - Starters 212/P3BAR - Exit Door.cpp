#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int main()
{
	int T,n,i,j,ra,rb,ans,a[12],pos[12];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			pos[a[i]]=i;
		}
		ans=0;
		for(i=n;i;i--)
		{
			a[pos[i]]=0;
			ra=rb=0;
			for(j=pos[i]-1;j>=1;j--)
			{
				if(a[j]) ra++;
			}
			for(j=pos[i]+1;j<=n;j++)
			{
				if(a[j]) rb++;
			}
			ans+=min(ra,rb);
		}
		printf("%d\n",ans);
	}
	return 0;
}
