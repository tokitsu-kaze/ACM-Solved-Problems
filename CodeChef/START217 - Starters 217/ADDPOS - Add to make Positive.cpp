#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int T,n,i,x,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			sum+=x;
		}
		if(sum>=0) puts("0");
		else printf("%d\n",(-sum+n-1)/n);
	}
	return 0;
}
