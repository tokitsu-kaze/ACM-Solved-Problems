////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 10:54:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2564
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
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
    int t,i;
    char a[201];
    while(cin>>t)
    {
		getchar();
		while(t--)
		{
			gets(a);
			if(a[0]!=' ') printf("%c",toupper(a[0]));
			for(i=1;i<strlen(a);i++)
			{
				if(a[i-1]==' '&&a[i]!=' ') printf("%c",toupper(a[i]));
			}
			puts("");
		}
	}
    return 0;
}
