#include <bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int MAXN=505;
struct discretization_node
{
    int num;
    int ki;
}disc[MAXN];
bool cmp(discretization_node x,discretization_node y)
{
    return x.num<y.num;
}
int discretization(int a[],int n,discretization_node disc[])
{
    for(int i=1;i<=n;++i)
    {
        disc[i].num=a[i];
        disc[i].ki=i;
    }
    sort(disc+1,disc+1+n,cmp);
    int cnt=0,pre;
    for(int i=1;i<=n;++i)
    {
        if(i==1||a[disc[i].ki]!=pre)cnt+=2;
        pre=a[disc[i].ki];
        a[disc[i].ki]=cnt;
    }
    return cnt+2;
}
int pos[MAXN],len,T;
bool vis[MAXN][MAXN];
void draw(int xl,int yl,int xr,int yr)
{
    for(int i=xl;i<=xr;++i)
    {
        for(int j=yl;j<=yr;++j)
        {
            vis[i][j]=true;
        }
    }
    return;
}
void dfs(int x,int y)
{
    vis[x][y]=true;
    for(int i=0;i<4;++i)
    {
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        if(new_x>=1&&new_x<=len&&new_y>=1&&new_y<=len&&!vis[new_x][new_y])
        {
            dfs(new_x,new_y);
        }
    }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        for(int i=1;i<=8;++i)
        {
            scanf("%d",&pos[i]);
        }
        len=discretization(pos,8,disc);
        for(int i=1;i<=len;++i)
        {
            for(int j=1;j<=len;++j)
            {
                vis[i][j]=false;
            }
        }
        draw(pos[1],pos[2],pos[1],pos[4]);
        draw(pos[1],pos[4],pos[3],pos[4]);
        draw(pos[1],pos[2],pos[3],pos[2]);
        draw(pos[3],pos[2],pos[3],pos[4]);
        draw(pos[1+4],pos[2+4],pos[1+4],pos[4+4]);
        draw(pos[1+4],pos[4+4],pos[3+4],pos[4+4]);
        draw(pos[1+4],pos[2+4],pos[3+4],pos[2+4]);
        draw(pos[3+4],pos[2+4],pos[3+4],pos[4+4]);
        int ans=0;
        for(int i=1;i<=len;++i)
        {
            for(int j=1;j<=len;++j)
            {
                if(!vis[i][j])
                {
                    ++ans;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

