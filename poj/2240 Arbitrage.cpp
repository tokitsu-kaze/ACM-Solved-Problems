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
	int n,i,j,k,m,flag=0,cas=1,flag2;
	string pa,pb;
	double r,map1[33][33];
	while(cin>>n&&n)
	{
		mem(map1,0);
		map<string,int> mp;
		for(i=1;i<=n;i++)
		{
			cin>>pa;
			mp[pa]=i;
		}
		cin>>m;
		while(m--)
		{
			cin>>pa>>r>>pb;
			map1[mp[pa]][mp[pb]]=r;
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					map1[i][j]=max(map1[i][j],map1[i][k]*map1[k][j]);
				}
			}
		}
		flag2=0;
		for(i=1;i<=n;i++)
		{
			if(map1[i][i]>1)
			{
				flag2=1;
				break;
			}
		}
		printf("Case %d: ",cas++);
		if(flag2) puts("Yes");
		else puts("No");
	}
    return 0;
}