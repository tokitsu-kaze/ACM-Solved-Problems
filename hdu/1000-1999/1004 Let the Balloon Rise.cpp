////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-27 21:30:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1504KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int main()
{
	int n,max;
	char s[16],c[16];
	map<string ,int> a;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		max=0;
		a.clear();
		while(n--)
		{
			scanf("%s",s);
			a[s]++;
			if(a[s]>max)
			{
				max=a[s];
				strcpy(c,s);
			}
		}
		printf("%s\n",c);
	}
}