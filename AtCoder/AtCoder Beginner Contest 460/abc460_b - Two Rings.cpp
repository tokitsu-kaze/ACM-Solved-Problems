#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
ll sqr(ll x){return x*x;}
int main()
{
	int T,x1,y1,r1,x2,y2,r2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2);
		if(sqr(x1-x2)+sqr(y1-y2)<sqr(r1-r2)) puts("No");
		else if(sqr(x1-x2)+sqr(y1-y2)<=sqr(r1+r2)) puts("Yes");
		else puts("No");
	}
	return 0;
}
