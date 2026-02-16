#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,ok,a[105];
	scanf("%d",&T);
	while(T--)
	{
		ok=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]%a[1]) ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
考虑 a2 怎么才能变为 0：a2%a1==0 时。 
再考虑 a3，显然 a3%a2==0 时可行，但有更优的情况。
会发现把 a2 变为 a1 时，转化成 a3%a1==0 
*/
