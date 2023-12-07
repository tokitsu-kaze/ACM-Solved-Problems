#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
int flag[MAX];
int main()
{
	int t,n,i,tot,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tot=0;
		for(i=1;i<=n+1;i++) flag[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(flag[x+1]) flag[x+1]=0;
			else tot++;
			flag[x]=1;
		}
		printf("%d\n",tot);
	}
	return 0;
}
