#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int n,d,t[105],l[105],i,j,k,ans;
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++) scanf("%d%d",&t[i],&l[i]);
	for(k=1;k<=d;k++)
	{
		ans=0;
		for(i=1;i<=n;i++) ans=max(ans,t[i]*(l[i]+k));
		printf("%d\n",ans);
	}
	return 0;
}

