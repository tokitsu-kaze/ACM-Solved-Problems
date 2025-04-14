#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	int T,i,j,g,n,k;
	ll l;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(2*k+1<=n)
		{
			printf("1 %d\n",2*k+1);
			continue;
		}
		for(i=2;i<=min(n,10);i++)
		{
			for(j=i+k;j<=min(n,i+k+20);j++)
			{
				g=__gcd(i,j);
				l=1LL*i/g*j;
				if(abs(g-l)>=2*k)
				{
					assert(i>=1 && i<=n);
					assert(j>=1 && j<=n);
					assert(abs(i-j)>=k);
					printf("%d %d\n",i,j);
					goto end;
				}
			}
		}
		puts("-1 -1");
		end:;
	}
	return 0;
}

