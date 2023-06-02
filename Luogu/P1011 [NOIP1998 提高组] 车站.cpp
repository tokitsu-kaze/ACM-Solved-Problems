#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int a,n,m,x,k,i;
	ll fib[33],now[33];
	scanf("%d%d%d%d",&a,&n,&m,&x);
	for(k=0;k<=m;k++)
	{
		fib[1]=a;
		fib[2]=k;
		now[1]=now[2]=a;
		for(i=3;i<=n-1;i++)
		{
			fib[i]=fib[i-1]+fib[i-2];
			now[i]=now[i-1]+fib[i]-fib[i-1];
			if(now[i]>m)
			{
				now[n]=m+1;
				break;
			}
		}
	//	printf("%d %lld\n",k,now[n-1]);
		if(now[n-1]==m)
		{
			printf("%lld\n",now[x]);
			break;
		}
	}
	return 0;
}
