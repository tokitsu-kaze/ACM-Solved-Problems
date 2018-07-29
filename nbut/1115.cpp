#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	double a[1111],ans;
	while(~scanf("%d",&n))
	{
		ans=0;
		for(i=0;i<n;i++) scanf("%lf",&a[i]);
		sort(a,a+n);
		for(i=1;i<n-1;i++) ans+=a[i];
		printf("%.2lf\n",ans/(n-2));
	}
	return 0;
}