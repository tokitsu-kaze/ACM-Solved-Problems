#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,i,j,f;
	double a[22],ans,tmp;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++) scanf("%lf",&a[i]);
		ans=0;
		for(i=1;i<(1<<n);i++)
		{
			f=-1;
			tmp=0;
			for(j=0;j<n;j++)
			{
				if((i>>j)&1)
				{
					f*=-1;
					tmp+=a[j];
				}
			}
			ans+=f/tmp;
		}
		printf("%.10f\n",ans);
	}
	return 0;
}
