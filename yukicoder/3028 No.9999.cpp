#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,now;
	scanf("%d",&n);
	now=0;
	for(i=1;;i++)
	{
		now=(now*10+9)%n;
		if(now==0)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
