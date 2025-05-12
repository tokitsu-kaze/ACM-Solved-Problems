#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,m,p,q;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&p,&q);
		if(n%p==0)
		{
			if(n/p*q==m) puts("YES");
			else puts("NO");
		}
		else puts("YES");
	}
	return 0;
}
