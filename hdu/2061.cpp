////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 15:33:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2061
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1636KB
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
    int t,n,flag;
    double a,b,sum1,sum2;
    char c[31];
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			sum1=sum2=flag=0;
			while(n--)
			{
				scanf("%s%lf%lf",c,&a,&b);
				sum1+=a*b;
				sum2+=a;
				if(b<60) flag=1;
			}
			if(flag) puts("Sorry!");
			else printf("%.2lf\n",sum1/sum2);
			if(t) puts("");
		}
	}
    return 0;
}
