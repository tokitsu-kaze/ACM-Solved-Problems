////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-04 13:20:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3665
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,i,j,k,m,p,s,l,mp[11][11],sea[11],ans;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				mp[i][j]=INF;
			}
		}
		mem(sea,0);
		for(i=0;i<n;i++)
		{
			cin>>m>>p;
			sea[i]=p;
			for(j=0;j<m;j++)
			{
				cin>>s>>l;
				mp[i][s]=l;
			}
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
				}
			}
		}
		ans=INF;
		for(i=0;i<n;i++)
		{
			if(sea[i])
			{
				ans=min(ans,mp[0][i]);
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}