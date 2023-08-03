#include <stdio.h>
#include <math.h>
#include <limits.h>
#define pi 4*atan(1.0)
int main()
{
	int t,n,m,i,count,r;
	double mid,lb,rb,s[10005],max;
	const double eps=1e-6;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&m,&n);
			max=INT_MIN;
			for(i=0;i<m;i++)
			{
				scanf("%d",&r);
				s[i]=pi*r*r;
				if(s[i]>max) max=s[i];
			}
			n++;
			lb=0;
			rb=max;
			while(rb-lb>eps)
			{
				mid=(lb+rb)/2;
				for(i=0,count=0;i<m;i++)
				{
					count+=(int)(s[i]/mid);
				}
				if(count<n) rb=mid;
				else if(count>=n) lb=mid;
			}
			printf("%.4f\n",mid);
		}
	}
	return 0;
}
