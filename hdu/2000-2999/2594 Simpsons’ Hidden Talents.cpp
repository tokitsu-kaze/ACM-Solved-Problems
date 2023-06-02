////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-10 15:37:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2594
////Problem Title: 
////Run result: Accept
////Run time:670MS
////Run memory:1812KB
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
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef double LD;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
int main()
{
	int lena,lenb,i,j,len,flag;
	char a[50010],b[50010],c[50010],*p;
	while(~scanf("%s%s",a,b))
	{
		lena=strlen(a);
		lenb=strlen(b);
		len=lenb-lena;
		if(len<0) len=0;
		flag=0;
		for(i=lenb-1,j=0;i>=len;i--,j++)
		{
			c[j]=a[j];
			c[j+1]='\0';
			if(c[0]==b[i])
			{
				if(strcmp(b+i,c)==0)
				{
					flag=1;
					p=b+i;
				}
			}
		}
		if(flag) printf("%s %d\n",p,strlen(p));
		else puts("0");
	}
	return 0;
}