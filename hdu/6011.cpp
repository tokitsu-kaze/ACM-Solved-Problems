////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-27 20:43:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6011
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1644KB
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
#define MAX 100000+10
using namespace std;
typedef long long ll;
int dp[110][110];
int main()
{
    ll t,n,i,v[3011],cnt,k,temp,sum1,sum2,ans; 
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			k=sum1=sum2=0;
			while(n--)
			{
				cin>>temp>>cnt;
				while(cnt--)
				{
					v[k++]=temp;
					if(temp>0) sum1+=temp;
					else sum2+=temp;
				}
			}
			sort(v,v+k);
			ans=0;
			for(i=0;i<k;i++)
			{
				ans+=v[i]*(i+1);
			}
			for(i=0;i<k;i++)
			{
				if(v[i]>=0) break;
				if(v[i]<0)
				{
					ans=max(ans,ans-sum1-sum2);
					sum2-=v[i];
				}
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}