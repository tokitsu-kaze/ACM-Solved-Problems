#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,x1,x2,x3,x4,ans,now;
	while(~scanf("%d%d%d%d",&a,&b,&c,&d))
	{
		if(a>0&&b>0&&c>0&&d>0)
		{
			puts("0");
			continue;
		}
		if(a<0&&b<0&&c<0&&d<0)
		{
			puts("0");
			continue;
		}
		map<int,int> mp;
		for(x1=1;x1<=100;x1++)
		{
			for(x2=1;x2<=100;x2++)
			{
				mp[a*x1*x1+b*x2*x2]++;
			}
		}
		ans=0;
		for(x3=1;x3<=100;x3++)
		{
			for(x4=1;x4<=100;x4++)
			{
				if(mp.count(-(c*x3*x3+d*x4*x4)))
				{
					ans+=mp[-(c*x3*x3+d*x4*x4)];
				}
			}
		}
		printf("%d\n",ans*16);
	}
	return 0;
}
