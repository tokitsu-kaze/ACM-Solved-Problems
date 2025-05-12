#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,s,m,i,l,r,pre,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&s,&m);
		ok=0;
		pre=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&l,&r);
			if(l-pre>=s) ok=1;
			pre=r;
		}
		if(m-pre>=s) ok=1;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}

