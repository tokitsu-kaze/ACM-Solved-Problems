////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-10 23:11:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,seed=239,x;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<9;j++)
			{
				scanf("%d",&x);
			}
		}
		if(seed&1) puts("YES");
		else puts("NO");
		seed>>=1;
	}
	return 0;
}