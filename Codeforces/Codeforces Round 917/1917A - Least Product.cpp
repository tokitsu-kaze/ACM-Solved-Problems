#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int T,n,i,a[105],x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		x=y=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<0) x++;
			else if(a[i]>0) y++;
		}
		if(x+y!=n)
		{
			puts("0");
			continue;
		}
		if(x&1) puts("0");
		else
		{
			puts("1");
			puts("1 0");
		}
	}
	return 0;
}
