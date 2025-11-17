#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,m,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		ans=0;
		a[0]=b[0]=0;
		for(i=1;i<=n;i++)
		{
			ans+=a[i]-a[i-1];
			if((((a[i]-a[i-1])&1)^(b[i-1]))!=b[i]) ans--;
		}
		ans+=m-a[n];
		printf("%d\n",ans);
	}
	return 0;
}
