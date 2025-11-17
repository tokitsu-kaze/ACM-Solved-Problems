#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,m,x,y,ans,i,a;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&x,&y);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(a<y) ans++;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d",&a);
			if(a<x) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
