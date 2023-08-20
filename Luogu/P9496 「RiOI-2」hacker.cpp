#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t,f1,f2,i;
	ll n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		if(n==m) puts("0");
		else
		{
			f1=f2=0;
			for(i=0;i<60;i++)
			{
				if(((n>>i)&1)&&!((m>>i)&1)) f1=1;
				else if(!((n>>i)&1)&&((m>>i)&1)) f2=1;
			}
			printf("%d\n",f1+f2);
		}
	}
	return 0;
}
