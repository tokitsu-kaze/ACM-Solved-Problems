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
#define MAX 200000+10
using namespace std;
typedef long long ll;
int dp[5010];
int main()
{ 
	int t,n,b,w[501],v[501],i,j,sum;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>b;
			sum=0;
			for(i=0;i<n;i++)
			{
				scanf("%d%d",&w[i],&v[i]);
				sum+=v[i];
			}
			mem(dp,0x3f);
			dp[0]=0;
			for(i=0;i<n;i++)
			{
				for(j=sum;j>=v[i];j--)
				{
					dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
				}
			}
			for(i=sum;i>=0;i--)
			{
				if(dp[i]<=b)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
	}
    return 0;
}