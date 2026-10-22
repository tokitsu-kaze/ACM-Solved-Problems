#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int T,a,b,c,m,l,r,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&m);
		r=a+b+c-3;
		mx=max({a,b,c});
		l=max(0,mx-(a+b+c-mx+1));
		if(l<=m && m<=r) puts("YES");
		else puts("NO");
	}
	return 0;
}
