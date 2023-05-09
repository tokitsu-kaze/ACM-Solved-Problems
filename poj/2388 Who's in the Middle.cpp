#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int t,a[10001],i; 
    while(~scanf("%d",&t))
    {
		for(i=0;i<t;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+t);
		printf("%d\n",a[(1+t)/2-1]);
    }
    return 0;
}