#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=30;~i;i--)
		{
			if((1<<i)<=n)
			{
				printf("%d\n",(1<<i)-1);
				break;
			}
		}
	}
	return 0;
}
