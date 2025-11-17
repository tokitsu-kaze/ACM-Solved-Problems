#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T;
	ll n,m,a,b,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
		if((m-b*n)%(a-b))
		{
			puts("No");
			continue;
		}
		x=(m-b*n)/(a-b);
		y=n-x;
		if(a*x+b*y==m && x>=0 && y>=0) puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
ax+by=m
x+y=n

y=n-x

ax+b(n-x)=m
ax+bn-bx=m
(a-b)x=m-bn
*/
