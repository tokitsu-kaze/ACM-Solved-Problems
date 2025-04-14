#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,i,n,x,y,a,b,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%d%d",&x,&y);
		ans=x;
		for(i=2;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a>=x)
			{
				if(b>=y) ans=-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

