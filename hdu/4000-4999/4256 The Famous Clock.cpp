////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-04 23:59:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4256
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1584KB
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
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int cas=1;
	char a[11];
	map<string,int> m;
	m["I"]=1;
	m["II"]=2;
	m["III"]=3;
	m["IV"]=4;
	m["V"]=5;
	m["VI"]=6;
	m["VII"]=7;
	m["VIII"]=8;
	m["IX"]=9;
	m["X"]=10;
	m["XI"]=11;
	m["XII"]=12;
	while(~scanf("%s",a))
	{
		printf("Case %d: %d\n",cas++,m[a]);
	}
	return 0;
}