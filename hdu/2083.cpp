////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 12:39:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2083
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1000000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int main()
{
    int i,t,n,a[501],sum;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
			sort(a,a+n);
			sum=0;
			for(i=0;i<n;i++)
			{
				sum+=abs(a[n/2]-a[i]);
			} 
			cout<<sum<<endl;
		}
	}
    return 0;
}
