////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-15 08:46:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4802
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1604KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int n,i,c;
	double a,b;
	char s[11];
	map<string,double> m;
	m["A"]=4.0;
	m["A-"]=3.7;
	m["B+"]=3.3;
	m["B"]=3.0;
	m["B-"]=2.7;
	m["C+"]=2.3;
	m["C"]=2.0;
	m["C-"]=1.7;
	m["D"]=1.3;
	m["D-"]=1.0;
	m["F"]=0;
	while(~scanf("%d",&n))
	{
		a=b=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%s",&c,s);
			if(s[0]=='P'||s[0]=='N') continue;
			a+=c*m[s];
			b+=c;
		}
		if(b) printf("%.2lf\n",a/b);
		else puts("0.00");
	}
	return 0;
}