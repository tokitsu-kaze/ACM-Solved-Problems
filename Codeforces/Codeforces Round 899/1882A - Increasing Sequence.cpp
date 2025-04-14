#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
int main()
{
	int T,n,i,a[105],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans++;
			if(a[i]==ans) ans=a[i]+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
