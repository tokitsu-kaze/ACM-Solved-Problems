////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 12:30:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2085
////Problem Title: 
////Run result: Accept
////Run time:46MS
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
    ll i,h[41],l[41],n;
    h[0]=1;
    l[0]=0;
    h[1]=3;
    l[1]=1;
    for(i=2;i<=33;i++)
    {
		h[i]=3*h[i-1]+2*l[i-1];
		l[i]=h[i-1]+l[i-1];
	}
    while(cin>>n)
    {
		if(n==-1) break;
		printf("%lld, %lld\n",h[n],l[n]);
	}
    return 0;
}
