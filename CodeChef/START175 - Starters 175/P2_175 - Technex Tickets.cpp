#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int main()
{
	int T,n,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n<=2)
		{
			printf("%d\n",n);
			continue;
		}
		ans=(n-2)/2;
		n-=ans*2;
		if(n&1) ans++;
		else ans+=2;
		printf("%d\n",ans);
	}
	return 0;
}
