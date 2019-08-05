////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-29 18:18:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3787
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1580KB
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
#define pi acos(-1.0) 
using namespace std;
typedef long long ll;
int main()
{
	int c,d,i;
	char a[21],b[21]; 
	while(~scanf("%s%s",a,b))
	{
		c=d=0;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]>='0'&&a[i]<='9') c=c*10+a[i]-'0';
		}
		if(a[0]=='-') c=-c;
		for(i=0;i<strlen(b);i++)
		{
			if(b[i]>='0'&&b[i]<='9') d=d*10+b[i]-'0';
		}
		if(b[0]=='-') d=-d;
		cout<<c+d<<endl;
	}
	return 0;
}
