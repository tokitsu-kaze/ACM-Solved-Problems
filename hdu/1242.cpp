////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-12 21:42:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1242
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 220;
char map[maxn][maxn];
int visited[maxn][maxn];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct node
{
    int x,y;
    int time;
    friend bool operator < (node a,node b)
    {
        return a.time>b.time;
    }
};
int n,m;
int go(int x,int y)
{
    if(0<=x&&x<n&&0<=y&&y<m&&map[x][y]!='#')
        return 1;
    else
        return 0;
}
int bfs(int x,int y)
{
    priority_queue<node>q;
    while(!q.empty())
        q.pop();
    memset(visited,0,sizeof(visited));
    node st,ed;
    st.x=x;
    st.y=y;
    st.time=0;
    visited[st.x][st.y]=1;
    q.push(st);
    while(!q.empty())
    {
        st=q.top();
        if(map[st.x][st.y]=='a')
            return st.time;
        q.pop();
        for(int i=0;i<4;i++)
        {
            ed.x=st.x+dir[i][0];
            ed.y=st.y+dir[i][1];
            if(go(ed.x,ed.y)&&!visited[ed.x][ed.y])
            {
                if(map[ed.x][ed.y]=='x')
                    ed.time=st.time+2;
                else
                    ed.time=st.time+1;
                visited[ed.x][ed.y]=1;
                q.push(ed);
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        int x=0,y=0,sum=0;
        memset(map,'\0',sizeof(map));
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(j=0;j<m;j++)
            {
                if(map[i][j]=='r')
                {
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        sum=bfs(x,y);
        if(sum==-1)
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        else
            printf("%d\n",sum);
    }
    return 0;
}