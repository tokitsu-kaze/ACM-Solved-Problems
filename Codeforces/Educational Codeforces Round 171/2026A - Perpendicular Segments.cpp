#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int T,x,y,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&x,&y,&k);
		if(k<=min(x,y))
		{
			printf("0 0 %d 0\n",k);
			printf("0 0 0 %d\n",k);
		}
		else
		{
			printf("0 0 %d %d\n",min(x,y),min(x,y));
			printf("%d 0 0 %d\n",min(x,y),min(x,y));
		}
	}
	return 0;
}
