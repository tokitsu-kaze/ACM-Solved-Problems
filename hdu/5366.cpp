////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-01-21 21:08:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5366
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1604KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100000000+10
using namespace std;
typedef long long ll;
int main()
{
    ll n,i,a[62];
    a[1]=1;
    a[2]=2;
    a[3]=3;
    for(i=4;i<=60;i++)
    {
		a[i]=a[i-1]+a[i-3]+1;
	}
    while(cin>>n)
    {
		cout<<a[n]<<endl;
    }
    return 0;
} 