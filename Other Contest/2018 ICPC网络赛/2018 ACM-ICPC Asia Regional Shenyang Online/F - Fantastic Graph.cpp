#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=50005,MAXM=500005<<1,INF=2147483647;
int g[MAXN];
struct edges
{
    int to,next,cap,flow;
} e[MAXM];
int tot=1,head,tail,q[MAXN],dis[MAXN],vist[MAXN],s,t,maxp,temp[MAXN],du[MAXN];
int min1(int a1,int b1)
{
    return a1<b1?a1:b1;
}
void adds(int a1,int b1,int c1)
{
    tot++;
    e[tot].to=b1;
    e[tot].cap=c1;
    e[tot].next=g[a1];
    e[tot].flow=0;
    g[a1]=tot;
    return;
}
void add_edge(int a1,int b1,int c1)
{
    adds(a1,b1,c1);
    adds(b1,a1,0);
    return;
}
bool bfs()
{
    for(int i=0; i<=maxp; i++)
    {
        vist[i]=false;
    }
    head=0;
    tail=1;
    q[tail]=s;
    vist[s]=true;
    while(head!=tail)
    {
        head++;
        int x=q[head];
        for(int i=g[x]; i; i=e[i].next)
        {
            if(e[i].cap>e[i].flow&&!vist[e[i].to])
            {
                tail++;
                q[tail]=e[i].to;
                vist[e[i].to]=true;
                dis[e[i].to]=dis[x]+1;
            }
        }
    }
    return vist[t];
}
int dfs(int now,int mins)
{
    if(now==t||mins==0)return mins;
    int now_flow=0,next_flow;
    for(; temp[now]; temp[now]=e[temp[now]].next)
    {
        if(dis[e[temp[now]].to]==dis[now]+1)
        {
            next_flow=dfs(e[temp[now]].to,min1(mins,e[temp[now]].cap-e[temp[now]].flow));
            if(next_flow>0)
            {
                e[temp[now]].flow+=next_flow;
                e[temp[now]^1].flow-=next_flow;
                now_flow+=next_flow;
                mins-=next_flow;
                if(mins==0)
                break;
            }
        }
    }
    return now_flow;
}
int dinic()
{
    int ans=0;
    while(bfs())
    {
        for(int i=0; i<=maxp; ++i)
        {
            temp[i]=g[i];
        }
        ans+=dfs(s,INF);
    }
    return ans;
}
int T,n,m,a,b,c,k,s1,t1,ss,tt,sumdu,L,R,u,v,cas;
void init()
{
    for(int i=0;i<=maxp;++i)
    {
        g[i]=du[i]=0;
    }
    tot=1;
    sumdu=0;
    return;
}
//s,t,maxp¼ÇµÃ¸³Öµ

int main()
{
    while(scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
        printf("Case %d: ",++cas);
        s1=n+m+1;
        t1=n+m+2;
        ss=n+m+3;
        tt=n+m+4;
        maxp=tt;
        init();
        scanf("%d %d",&L,&R);
        for(int i=1;i<=n;++i)
        {
            du[i]+=L;
            du[s1]-=L;
            add_edge(s1,i,R-L);
        }
        for(int i=1;i<=m;++i)
        {
            du[t1]+=L;
            du[i+n]-=L;
            add_edge(i+n,t1,R-L);
        }
        for(int i=1;i<=k;++i)
        {
            scanf("%d %d",&u,&v);
            add_edge(u,n+v,1);
        }
        for(int i=1;i<=maxp;++i)
        {
            if(du[i]>0)
            {
                add_edge(ss,i,du[i]);
                sumdu+=du[i];
            }
            if(du[i]<0)
            {
                add_edge(i,tt,-du[i]);
            }
        }
        add_edge(t1,s1,INF);
        s=ss;
        t=tt;
        if(dinic()==sumdu)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}