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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 1000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int edge[MAX][MAX];
int cost[MAX];
int path[MAX][MAX];
int n;
void floyd()
{
	int i,j,k,temp;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			path[i][j]=j;
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				temp=edge[i][k]+edge[k][j]+cost[k];
				if(edge[i][j]>temp)
				{
					edge[i][j]=temp;
					path[i][j]=path[i][k];
				}
				else if(edge[i][j]==temp)
				{
					path[i][j]=min(path[i][j],path[i][k]);
				}
			}
		}
	}
}
int main()
{
    int i,j,s,e,temp;
    while(cin>>n&&n)
    {
		mem(edge,0);
        for(i=1;i<=n;i++)
        {
			for(j=1;j<=n;j++)
			{
				scanf("%d",&edge[i][j]);
				if(edge[i][j]==-1) edge[i][j]=INF;
			}
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&cost[i]);
		}
		floyd();
		while(scanf("%d%d",&s,&e)!=-1)  
        {  
            if(s==-1 && e==-1)  break;  
            printf("From %d to %d :\n",s,e);  
            printf("Path: %d",s);  
            temp=s;  
            while(temp!=e)  
            {  
                printf("-->%d",path[temp][e]);  
                temp=path[temp][e];  
            }  
            printf("\n");  
            printf("Total cost : %d\n\n",edge[s][e]);  
        }  
    }
    return 0;
}