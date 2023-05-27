////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-10 15:17:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2140
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1560KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef long long ll;
int main()
{
	int i;
	char a;
	map<char,char>m;
	m.clear();
	m['b']=' ';
	m['q']=',';
	m['t']='!';
	m['m']='l';
	m['i']='e';
	m['c']='a';
	m['a']='c';
	m['e']='i';
	m['l']='m';
	while((a=getchar())!=EOF)
	{
		if(m[a]) printf("%c",m[a]);
		else printf("%c",a);
	}
    return 0;
}
