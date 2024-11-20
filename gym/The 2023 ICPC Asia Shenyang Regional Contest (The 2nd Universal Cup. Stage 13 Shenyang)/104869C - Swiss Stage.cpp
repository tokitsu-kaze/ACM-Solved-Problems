#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int main()
{
	int x,y,ans;
	scanf("%d%d",&x,&y);
	ans=0;
	while(x<2 && y<2)
	{
		ans++;
		x++;
	}
	while(x<3)
	{
		ans+=2;
		x++;
	}
	printf("%d\n",ans);
	return 0;
}
