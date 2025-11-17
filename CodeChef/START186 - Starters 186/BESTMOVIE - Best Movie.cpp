#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,a,b,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a>=7) ans=min(ans,b);
		}
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
