#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int i;
	unsigned long long x,now;
	scanf("%llu",&x);
	now=1;
	for(i=1;;i++)
	{
		now=now*i;
		if(now==x)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
