#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,a,b,c,d,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ans=0;
		if((a>=c && b>d) || (a>c && b>=d)) ans++;
		if((a>=d && b>c) || (a>d && b>=c)) ans++;
		if((b>=c && a>d) || (b>c && a>=d)) ans++;
		if((b>=d && a>c) || (b>d && a>=c)) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
