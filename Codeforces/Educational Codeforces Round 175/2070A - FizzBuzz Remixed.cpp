#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int main()
{
	int T,n,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=n/15*3;
		n%=15;
		ans+=min(3,n+1);
		printf("%d\n",ans);
	}
	return 0;
}
