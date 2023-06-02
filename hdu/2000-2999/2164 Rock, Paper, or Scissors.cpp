////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 21:33:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2164
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1608KB
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
typedef long long ll;
int main()
{
	int n,t,flag1,flag2;
	char a,b;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			flag1=flag2=0;
			while(n--)
			{
				getchar();
				scanf("%c %c",&a,&b);
				if((a=='R'&&b=='S')||(a=='S'&&b=='P')||(a=='P'&&b=='R')) flag1++;
				else if((a=='S'&&b=='R')||(a=='P'&&b=='S')||(a=='R'&&b=='P')) flag2++;
			}
			if(flag1>flag2) puts("Player 1");
			else if(flag1<flag2) puts("Player 2");
			else puts("TIE");
		}
	}
    return 0;
}