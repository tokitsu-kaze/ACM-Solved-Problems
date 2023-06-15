#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,i,x,g;
	scanf("%d",&n);
	g=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		g=__gcd(g,abs(x));
	}
	printf("%d\n",g);
	return 0;
}
