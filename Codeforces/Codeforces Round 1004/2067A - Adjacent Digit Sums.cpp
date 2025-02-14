#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=2e5+10;
int main()
{
	int T,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		if(x+1==y)
		{
			puts("Yes");
			continue;
		}
		if(x<y)
		{
			puts("No");
			continue;
		}
		if((x-y+1)%9==0) puts("Yes");
		else puts("No");
	}
	return 0;
}
