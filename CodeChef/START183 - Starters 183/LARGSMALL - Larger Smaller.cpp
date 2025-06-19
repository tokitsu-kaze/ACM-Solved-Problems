#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,mx,mn,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		mx=0;
		mn=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mx=max(mx,x);
			mn=min(mn,x);
		}
		printf("%d\n",max(0,mx-mn-1));
	}
	return 0;
}
