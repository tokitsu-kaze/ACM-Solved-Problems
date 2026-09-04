#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,ans,now;
	scanf("%d",&n);
	ans=now=0;
	for(i=1;i<=n;i++)
	{
		now+=i;
		ans+=now;
	}
	printf("%d\n",ans);
	return 0;
}
