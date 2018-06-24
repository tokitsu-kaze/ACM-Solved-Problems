////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 11:04:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2563
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1588KB
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
    int t,i,a[21],n;
    a[0]=1;
    a[1]=3;
    for(i=2;i<=20;i++)
    {
		a[i]=2*a[i-1]+a[i-2];
	}
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			cout<<a[n]<<endl;
		}
	}
    return 0;
}
