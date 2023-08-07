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
int dis[MAX];
int flag[MAX];
int n,s,d,si[MAX],di[MAX];
void init()
{
    int i,j;
    for(i=1;i<=MAX;i++)
    {
        flag[i]=0;
        dis[i]=INF;
        for(j=1;j<=MAX;j++)
        {
            edge[i][j]=INF;
        }
    }
}
void spfa()
{
    int i,now;
    queue<int> q;
    for(i=0;i<s;i++)
    {
        dis[si[i]]=0;
        flag[si[i]]=1;
        q.push(si[i]);
    }
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        flag[now]=0;
        for(i=1;i<=n;i++)
        {
            if(dis[i]>dis[now]+edge[now][i])
            {
                dis[i]=dis[now]+edge[now][i];
                if(!flag[i])
                {
                    q.push(i);
                    flag[i]=1;
                }
            }
        }
    }
}
int main()
{
    int t,a,b,c,ans,i;
    while(cin>>t>>s>>d)
    {
        init();
        n=0;
        while(t--)
        {
            scanf("%d%d%d",&a,&b,&c);
            n=max(n,max(a,b));
            if(edge[a][b]>c) edge[a][b]=edge[b][a]=c;
        }
        for(i=0;i<s;i++)
        {
            scanf("%d",&si[i]);
        }
        for(i=0;i<d;i++)
        {
            scanf("%d",&di[i]);
        }
        spfa();
        ans=INF;
        for(i=0;i<d;i++)
        {
            ans=min(ans,dis[di[i]]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
