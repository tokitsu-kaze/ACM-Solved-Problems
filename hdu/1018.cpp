////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-08 22:18:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#define pi 3.1415926
#define e 2.71828182
using namespace std;
int main()  
{
	int n,k,a;
	while(cin>>n)
	{	
		while(n--)
		{
			scanf("%d",&a);
			k=(int)(log10(sqrt(2*pi*a))+a*log10(a/e));
			printf("%d\n",k+1);
		}
    }
    return 0;  
}  
  