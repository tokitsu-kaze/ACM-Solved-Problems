#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		if(b==1)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%d %lld %lld\n",a,1LL*a*b,1LL*a*b+a);
	}
	return 0;
}
