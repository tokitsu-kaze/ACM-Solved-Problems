////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-28 17:19:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3785
////Problem Title: 
////Run result: Accept
////Run time:655MS
////Run memory:1968KB
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
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int a[100010];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{ 
	int i,n,m;
    while(~scanf("%d%d",&n,&m))
	{  
		if(n+m==0) break;
        for(i=0;i<n;i++)
        {
			scanf("%d",&a[i]);
		}
		sort(a,a+n,cmp);
		if(n<m) m=n;
		for(i=0;i<m;i++)
		{
			printf("%d",a[i]);
			if(i!=m-1) printf(" ");
			else puts("");
		}
    }  
    return 0;  
}  