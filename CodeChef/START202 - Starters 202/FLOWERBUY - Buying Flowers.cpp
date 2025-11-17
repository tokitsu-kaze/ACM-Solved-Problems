#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+11;
int main()
{
	int T,n,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=n/3*5;
		n%=3;
		if(n==1)
		{
			ans-=5;
			n+=3;
			ans+=n/2*4;
		}
		else if(n==2) ans+=4;
		printf("%d\n",ans);
	}
	return 0;
}
