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
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int m,n,dir[4][2]={0,1,1,0,0,-1,-1,0};
char mp[MAX][MAX];
int check(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m) return 0;
	return 1;
}
int main()
{
	int i,j,k,cnt,x,y;
	char key;
	while(~scanf("%d %d %c",&n,&m,&key))
	{
		mem(mp,0);
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
		}
		cnt=0;
		map<char,int> m1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(mp[i][j]==key)
				{
					for(k=0;k<4;k++)
					{
						x=i+dir[k][0];
						y=j+dir[k][1];
						if(check(x,y)&&mp[x][y]!='.'&&mp[x][y]!=key)
						{
							if(!m1[mp[x][y]])
							{
								cnt++;
								m1[mp[x][y]]=1;
							}
						}
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}