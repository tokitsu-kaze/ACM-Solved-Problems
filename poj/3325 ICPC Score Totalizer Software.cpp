#include <iostream>
#include <algorithm>
using namespace std;
int main ()  
{
    int i,n,a[1001],sum;
    while(cin>>n)
	{
		if(n==0) break;
		for(i=0,sum=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+n);
		cout<<(sum-a[0]-a[n-1])/(n-2)<<endl;
	}
    return 0;  
}