////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 19:04:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1216
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:1800KB
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
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int ans[3010],prime[50010];
int main()
{
    int n,i,j,k,t;
    mem(ans,0);
    mem(prime,0);
    t=1;
    for(i=2;;i++)
    {
		if(!prime[i])
		{
			ans[t++]=i;
			k=0;
			for(j=i+1;j<50010;j++)
			{
				if(!prime[j])
				{
					k++;
					if(k==i)
					{
						k=0;
						prime[j]=1;
					}
				}
			}
		}
		if(t==3000) break;
	}
    while(cin>>n&&n)
    {
		cout<<ans[n]<<endl;
	}
    return 0;
}
