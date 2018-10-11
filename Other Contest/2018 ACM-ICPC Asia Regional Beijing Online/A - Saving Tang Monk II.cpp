#include<bits/stdc++.h>
using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int MAXN=105;
long long dis[MAXN][MAXN][10],ans;
bool done[MAXN][MAXN][10];
char s[MAXN][MAXN];
int n,m,sx,sy,tx,ty;
struct node
{
    int x,y,ki;
    long long dis;
    friend bool operator < (const node &a,const node &b)
    {
        return a.dis>b.dis;
    }
    node(){}
    node(int _x,int _y,int _ki,long long _dis)
    {
        x=_x;
        y=_y;
        ki=_ki;
        dis=_dis;
    }
};
priority_queue<node>q;
bool check1(int x,int y)
{
    if(x>n||x<1||y>m||y<1)return false;
    return true;
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        while(!q.empty())q.pop();
        for(int i=1;i<=n;++i)
        {
            scanf("%s",s[i]+1);
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                for(int k=0;k<=5;++k)
                {
                    dis[i][j][k]=1152921504606846976LL;
                    done[i][j][k]=false;
                }
                if(s[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                    s[i][j]='.';
                    dis[i][j][0]=0;
                    q.push(node(i,j,0,0));
                }
                if(s[i][j]=='T')
                {
                    tx=i;
                    ty=j;
                    s[i][j]='.';
                }

            }
        }
        while(!q.empty())
        {
            node now=q.top();
            q.pop();
            if(done[now.x][now.y][now.ki])continue;
            for(int dir=0;dir<4;++dir)
            {
                int new_x=now.x+dx[dir];
                int new_y=now.y+dy[dir];
                if(check1(new_x,new_y))
                {
                    if(s[new_x][new_y]=='.')
                    {
                        if(dis[new_x][new_y][now.ki]>dis[now.x][now.y][now.ki]+1)
                        {
                            dis[new_x][new_y][now.ki]=dis[now.x][now.y][now.ki]+1;
                            q.push(node(new_x,new_y,now.ki,dis[new_x][new_y][now.ki]));
                        }
                    }
                    if(s[new_x][new_y]=='P')
                    {
                        if(dis[new_x][new_y][now.ki]>dis[now.x][now.y][now.ki])
                        {
                            dis[new_x][new_y][now.ki]=dis[now.x][now.y][now.ki];
                            q.push(node(new_x,new_y,now.ki,dis[new_x][new_y][now.ki]));
                        }
                    }
                    if(s[new_x][new_y]=='#'&&now.ki!=0)
                    {
                        if(dis[new_x][new_y][now.ki-1]>dis[now.x][now.y][now.ki]+2)
                        {
                            dis[new_x][new_y][now.ki-1]=dis[now.x][now.y][now.ki]+2;
                            q.push(node(new_x,new_y,now.ki-1,dis[new_x][new_y][now.ki-1]));
                        }
                    }
                    if(s[new_x][new_y]=='B')
                    {
                        if(dis[new_x][new_y][min(5,now.ki+1)]>dis[now.x][now.y][now.ki]+1)
                        {
                            dis[new_x][new_y][min(5,now.ki+1)]=dis[now.x][now.y][now.ki]+1;
                            q.push(node(new_x,new_y,min(5,now.ki+1),dis[new_x][new_y][min(5,now.ki+1)]));
                        }
                    }
                }
            }
            done[now.x][now.y][now.ki]=true;
        }
        ans=dis[tx][ty][0];
        for(int i=1;i<=5;++i)
        {
            ans=min(ans,dis[tx][ty][i]);
        }
        if(ans==1152921504606846976LL)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n",ans);
        }
    }
    return 0;
}