#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int T,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&l,&r);
		if(l==1 && r==1) puts("1");
		else printf("%d\n",r-l);
	}
	return 0;
}
