#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],ans[MAX];
int main()
{
	int T,n,l,r,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&l,&r);
		ok=1;
		for(i=1;i<=n;i++)
		{
			ans[i]=(l+i-1)/i*i;
			if(ans[i]>r) ok=0;
		}
		if(ok)
		{
			puts("YES");
			for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
		}
		else puts("NO");
	}
	return 0;
}
/*
考虑 gcd(ai,i)=i，在 [l,r] 中找 i 倍数即可。
*/
