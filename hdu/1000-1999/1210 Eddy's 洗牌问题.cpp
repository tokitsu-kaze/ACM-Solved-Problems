////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-03 18:14:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1210
////Problem Title: 
////Run result: Accept
////Run time:15MS
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
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef __int64 ll;
//typedef long long ll;
int main()
{
	int n,pos,cnt;
	while(cin>>n)
	{
		pos=1;
		cnt=0;
		n*=2;
		while(1)
		{
			pos=pos*2%(n+1);
			cnt++;
			if(pos==1) break;
		}
		cout<<cnt<<endl;
	}
    return 0;
}