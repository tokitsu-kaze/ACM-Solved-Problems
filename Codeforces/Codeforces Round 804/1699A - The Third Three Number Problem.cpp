#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int T,a,b,c,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n&1)
		{
			puts("-1");
			continue;
		}
		printf("%d %d %d\n",n/2,n/2,0);
	}
	return 0;
}
