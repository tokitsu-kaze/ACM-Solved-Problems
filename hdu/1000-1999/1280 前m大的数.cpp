////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-04 19:56:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1280
////Problem Title: 
////Run result: Accept
////Run time:717MS
////Run memory:19232KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int a[3010],b[4500010]; 
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
    int n,m,i,j,k;
    while(cin>>n>>m)
    {
		mem(a,0);
		mem(b,0);
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				b[k++]=a[i]+a[j];
			}
		}
		sort(b,b+k,cmp);
		for(i=0;i<m;i++)
		{
			printf("%d",b[i]);
			if(i!=m-1) printf(" ");
		}
		puts("");
	}
    return 0;
}
