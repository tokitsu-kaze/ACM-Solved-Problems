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
		if(x<y) puts("2");
		else if(x==y) puts("-1");
		else
		{
			if(x>y+1 && y>1) puts("3");
			else puts("-1");
		}
	}
	return 0;
}
