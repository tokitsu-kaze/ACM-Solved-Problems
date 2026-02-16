#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int T,n,m,i,mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		if(n==1||m==1)
		{
			puts("YES");
			continue;
		}
		mn=n;
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				mn=i;
				break;
			}
		}
		if(mn>m) puts("YES");
		else puts("NO");
	}
	return 0;
}
