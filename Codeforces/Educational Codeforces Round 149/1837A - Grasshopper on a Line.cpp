#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(n%k)
		{
			puts("1");
			printf("%d\n",n);
		}
		else
		{
			puts("2");
			printf("%d %d\n",n-1,1);
		}
	}
	return 0;
}
