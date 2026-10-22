#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
int main()
{
	int T,n,i;
	ll now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1) puts("1");
		else if(n==2) puts("-1");
		else
		{
			printf("2 4 6");
			now=6;
			for(i=4;i<=n;i++)
			{
				now*=2;
				printf(" %lld",now);
			}
			puts("");
		}
	}
	return 0;
}
