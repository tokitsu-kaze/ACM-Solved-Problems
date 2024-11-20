#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t,n,a,b,c,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a=b=c=-1;
		for(i=1;i<=10;i++)
		{
			if(i%3==0) continue;
			for(j=i+1;j<=10;j++)
			{
				if(j%3==0) continue;
				if((n-i-j)%3==0) continue;
				a=i;
				b=j;
				c=n-i-j;
				if(c<=0||c==a||c==b) a=b=c=-1;
				else goto end;
			}
		}
		end:;
		if(a==-1) puts("NO");
		else
		{
			puts("YES");
			printf("%d %d %d\n",a,b,c);
		}
	}
	return 0;
}
