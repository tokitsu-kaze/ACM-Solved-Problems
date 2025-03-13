#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int main()
{
	int T,x,y,k,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&x,&y,&k);
		tmp=abs(x-y);
		if((tmp-k)%2!=0) puts("-1");
		else printf("%d\n",abs(tmp-k)/2);
	}
	return 0;
}
