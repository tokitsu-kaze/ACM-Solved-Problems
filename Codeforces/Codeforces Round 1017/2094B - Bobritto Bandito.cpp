#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,m,l,r,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&l,&r);
		x=n-m;
		if(r<x)
		{
			x-=r;
			r=0;
			l+=x;
		}
		else r-=x;
		printf("%d %d\n",l,r);
	}
	return 0;
}
