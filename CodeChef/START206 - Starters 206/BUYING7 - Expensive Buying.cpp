#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,i,c[105],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&c[i]);
		sort(c+1,c+1+n);
		reverse(c+1,c+1+n);
		ans=0;
		for(i=1;i<=k;i++) ans+=c[i];
		printf("%d\n",ans);
	}
	return 0;
}

