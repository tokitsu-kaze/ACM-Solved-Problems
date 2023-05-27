////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-05 23:56:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2067
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1564KB
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
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    __int64 i,j,n,k,a[41],temp;
    mem(a,0);
    a[0]=1;
    a[1]=1;
    for(i=2;i<=35;i++)
    {
		temp=0;
		for(j=0;j<=i;j++)
		{
			temp+=a[j]*a[i-j-1];
		}
		a[i]=temp;
	}
	k=1;
    while(~scanf("%I64d",&n))
    {
		if(n==-1) break;
		printf("%I64d %I64d %I64d\n",k++,n,2*a[n]);
	}
    return 0;
}
