#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e4+10;
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=0;
		while(n>0)
		{
			n-=2;
			ans+=max(0,n-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}

