////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-28 14:58:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1256
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1612KB
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
	int i,j,t,n,p,q,flag;
	char c;
	while(cin>>t)
	{
		flag=0;
		while(t--)
		{
			if(flag) puts("");
			getchar();
			scanf("%c %d",&c,&n);
			q=(n+6)/6;
			p=2*((n+6)/6)+(n-2)/2;		
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=p;j++)
				{
					if(i==1||i==n||i==n-p+2*q-1)
					{
						if(j>q&&j<=p-q) cout<<c;
						if(j<=q) cout<<" ";
					}
					else
					{
					    if(j>q&&j<=p-q) cout<<" ";
						else cout<<c;
					}
				}
				puts("");
			}
			flag=1;
		}
	}
	return 0;
}