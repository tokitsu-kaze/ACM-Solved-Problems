#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
int res[MAX];
int main()
{
	int t,op,n,x,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&op,&n,&x);
		if(op==1)
		{
			if(x-(n-2)<=0)
			{
				puts("-1");
				continue;
			}
			for(i=1;i<=n-2;i++) res[i]=1;
			x-=n-2;
			res[n-1]=res[n]=x;
		}
		else
		{
			if(x-(n-2)<=0)
			{
				puts("-1");
				continue;
			}
			for(i=1;i<=n-1;i++) res[i]=1;
			x-=n-2;
			res[n]=x;
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
