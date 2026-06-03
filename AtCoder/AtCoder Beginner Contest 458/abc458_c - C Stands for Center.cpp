#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
char s[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]!='C') continue;
		ans+=min(i,n-i+1);
	}
	printf("%lld\n",ans);
	return 0;
}
