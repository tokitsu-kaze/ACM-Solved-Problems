#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",x+y+max(abs(x-y)-1,0));
	}
	return 0;
}

