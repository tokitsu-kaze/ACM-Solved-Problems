#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],sufmx[MAX];
int main()
{
	int T,n,x,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		sufmx[n+1]=-1;
		for(i=n;i;i--) sufmx[i]=max(sufmx[i+1],a[i]);
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(x>=b[i] && x-1>=sufmx[i+1])
			{
				x--;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

