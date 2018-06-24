////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-25 18:35:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1860
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1536KB
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
using namespace std;
int main()
{
	int i;
	char a[6],b[81];
	map<char,int> m;
	while(gets(a))
	{
		if(a[0]=='#') break;
		m.clear();
//		getchar();
		gets(b);
		for(i=0;i<strlen(b);i++)
		{
			m[b[i]]++;
		}
		for(i=0;i<strlen(a);i++)
		{
			printf("%c %d\n",a[i],m[a[i]]);
		}
	}
	return 0;
}