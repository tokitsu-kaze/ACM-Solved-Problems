#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		ans=0;
		if(n&1)
		{
			if(k%2==0) n-=k-1;
			else n-=k;
			ans++;
			if(n<=0)
			{
				puts("1");
				continue;
			}
		}
		k=k/2*2;
		ans+=(n+k-1)/k;
		printf("%d\n",ans);
	}
	return 0;
}
