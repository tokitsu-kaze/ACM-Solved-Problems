#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ans=1LL*n*(n+1)/2;
		for(i=1;i<n;i++)
		{
			if(s[i]==s[i+1]) ans-=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
