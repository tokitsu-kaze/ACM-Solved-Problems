#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,x,y,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&m,&x,&y,&d);
		if((x-d<=1&&x+d>=n)||(y-d<=1&&y+d>=m)) puts("-1");
		else if((x-d<=1&&y-d<=1)||(x+d>=n&&y+d>=m)) puts("-1");
		else if((n-x)+(m-y)<=d) puts("-1");
		else printf("%d\n",n+m-2);
	}
	return 0;
}
