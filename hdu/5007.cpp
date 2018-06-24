////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-16 18:20:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5007
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
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 10000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int i,len;
	string s;
	while(cin>>s)
	{
		len=s.length();
		for(i=0;i<len;i++)
		{
			if(s.substr(i,4)=="iPod"||s.substr(i,4)=="iPad") puts("MAI MAI MAI!");
			if(s.substr(i,4)=="Sony") puts("SONY DAFA IS GOOD!");
			if(s.substr(i,5)=="Apple") puts("MAI MAI MAI!");
			if(s.substr(i,6)=="iPhone") puts("MAI MAI MAI!");
		}
	}
    return 0;
}