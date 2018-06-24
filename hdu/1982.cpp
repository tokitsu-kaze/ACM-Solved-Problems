////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-09 21:59:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1982
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=100000+10;
const ll mod=10000;
int main()
{
	int t,i,len,temp;
	char a[11111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		len=strlen(a);
		temp=0;
		for(i=0;i<len;i++)
		{
			if(!(a[i]>='0'&&a[i]<='9'))
			{
				if(temp) putchar(temp-1+'A');
				temp=0;
			}
			if(a[i]=='-')
			{
				while(i+1<len&&a[i+1]=='-') i++;
				continue;
			}
			else if(a[i]=='#') putchar(' ');
			else temp=temp*10+a[i]-'0';
		}
		if(temp) putchar(temp-1+'A');
		puts("");
	}
	return 0;
}