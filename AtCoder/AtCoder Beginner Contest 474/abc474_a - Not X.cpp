#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int x,i;
	scanf("%d",&x);
	for(i=1;i<=3;i++)
	{
		if(i!=x)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
