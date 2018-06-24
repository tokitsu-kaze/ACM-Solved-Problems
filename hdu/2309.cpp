////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 17:49:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2309
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
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