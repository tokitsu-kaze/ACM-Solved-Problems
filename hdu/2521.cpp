////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 22:16:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2521
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1600KB
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
//typedef __int64 ll;
typedef long long ll;
int cntfac(int a)
{
	int i,cnt=0;
	for(i=1;i<=sqrt(a*1.0);i++)
	{
		if(a%i==0)
		{
			if(i*i!=a) cnt+=2;
			else cnt+=1;
		}
	}
	return cnt;
}
int main()
{
	int t,a,b,i,max,temp,ans;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>a>>b;
			max=0;
			for(i=a;i<=b;i++)
			{
				temp=cntfac(i);
				if(temp>max)
				{
					max=temp;
					ans=i;
				}
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}