#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	int T,n,k,i,j,pos,ok,a[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		{
			ok=1;
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				if(abs(a[i]-a[j])%k==0)
				{
					ok=0;
					break;
				}
			}
			if(ok)
			{
				puts("YES");
				printf("%d\n",i);
				goto end;
			}
		}
		puts("NO");
		end:;
	}
	return 0;
}
