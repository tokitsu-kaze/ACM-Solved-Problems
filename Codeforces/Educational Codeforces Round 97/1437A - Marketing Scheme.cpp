#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&l,&r);
		if(l*2<=r) puts("NO");
		else puts("YES");
	}
	return 0;
}
