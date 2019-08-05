////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-09 16:23:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2399
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=100000+10;
const ll mod=10000;
int main()
{
	int i;
	double s;
	char a[1111];
	map<char,int> m;
	m['A']=5;
	m['B']=4;
	m['C']=3;
	m['D']=2;
	m['F']=1;
	while(gets(a))
	{
		s=0;
		for(i=0;i<strlen(a);i+=2)
		{
			if(m[a[i]])
			{
				s+=m[a[i]];
				s--;
			}
			else
			{
				i=-1;
				break;
			}
		}
		if(i==-1) puts("Unknown letter grade in input");
		else printf("%.2lf\n",s/(strlen(a)/2+1));
	}
	return 0;
}