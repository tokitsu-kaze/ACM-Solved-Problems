////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-08 12:53:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3808
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1596KB
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
	int n,t;
	map<int,string> mp;
	mp[1]="Yu Jian";
	mp[2]="Tin O O";
	mp[3]="I Missed";
	mp[4]="Stefanie";
	mp[5]="The Same";
	mp[8]="About";
	mp[9]="Honey Honey";
	mp[10]="Unfinished";
	mp[11]="Hey Jude";
	mp[12]="When Winter Fades";
	while(~scanf("%d",&t))
	{
		puts("Best wishes to Stefanie");
		puts("");
		while(t--)
		{
			scanf("%d",&n);
			n%=14;
			cout<<mp[n]<<endl;
		}
	}
}
