////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-11 15:47:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1577
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1568KB
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
const double eps=1e-12;
const int MAX=2e6+10;
const ll mod=1e6;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	int l,sx,sy,px,py,g;
	while(~scanf("%d",&l)&&l)
	{
		scanf("%d%d%d%d",&sx,&sy,&px,&py);
		if(abs(px)>l||abs(py)>l)
		{
			puts("Out Of Range");
			continue;
		}
		g=gcd(abs(px-sx),abs(py-sy));
		if(g==1) puts("Yes");
		else puts("No");
	}
	return 0;
}