#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
int main()
{
	int n,i,j,k,v,w[105],ans;
	scanf("%d%d",&n,&v);
	for(i=1;i<=n;i++) scanf("%d",&w[i]);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(k=j+1;k<=n;k++)
			{
				if(i+j+k<=v) ans=max(ans,w[i]+w[j]+w[k]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
