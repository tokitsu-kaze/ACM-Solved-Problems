////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-01-21 21:25:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1671
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:1704KB
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

struct phone
{
	char tel[11];
}a[10010];
int cmp(const void *a,const void *b)
{
	struct phone *c=(struct phone *)a;
	struct phone *d=(struct phone *)b;
	return strcmp(c->tel,d->tel)>0?1:-1;
}
int main()
{
    int t,n,i,k,flag;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			getchar();
			mem(a,0);
			for(i=0;i<n;i++)
			{
				gets(a[i].tel);
			}
			qsort(a,n,sizeof(a[0]),cmp);
			for(i=0;i<n-1;i++)
			{
				for(k=0,flag=0;k<min(strlen(a[i].tel),strlen(a[i+1].tel));k++)
				{
					if(a[i].tel[k]!=a[i+1].tel[k])
					{
						flag=1;
						break;
					}
				}
				if(!flag) break;
			}
			if(!flag) puts("NO");
			else puts("YES");
		}
    }
    return 0;
} 