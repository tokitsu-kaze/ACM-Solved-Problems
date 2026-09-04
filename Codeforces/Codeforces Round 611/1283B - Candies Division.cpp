#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		ans=n-n%k;
		ans+=min(n%k,k/2);
		printf("%d\n",ans);
	}
	return 0;
}
