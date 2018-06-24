////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 14:58:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2068
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1604KB
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
    ll i,n,a[14],s,k,ans,j;
    a[0]=1;
    a[1]=0;
    a[2]=1;
    for(i=3;i<=13;i++)
    {
		a[i]=(i-1)*(a[i-1]+a[i-2]);
	}
    while(cin>>n&&n)
    {
		
		ans=0;
		for(i=0;i<=n/2;i++)
		{
			k=s=1;
			for(j=1;j<=i;j++)
			{
				k*=j;
				s*=n-j+1;
			}
			ans+=s/k*a[i];
		}
		cout<<ans<<endl;
	}
    return 0;
}
