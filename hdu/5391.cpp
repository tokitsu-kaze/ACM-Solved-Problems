////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-01-21 21:08:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5391
////Problem Title: 
////Run result: Accept
////Run time:967MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100000000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,n,i,j,flag;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			if(n==4)
			{
				puts("2");
				continue;
			}
			for(i=2,flag=0;i*i<=n;i++)
			{
				if(n%i==0)
				{
					flag=1;
					break;
				}
			}
			if(flag) puts("0");
			else cout<<n-1<<endl;
		}
    }
    return 0;
} 