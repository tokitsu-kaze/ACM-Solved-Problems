#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,x,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ans^=x;
		}
		if(ans) puts("Yes");
		else puts("No");
	}
	return 0;
}

