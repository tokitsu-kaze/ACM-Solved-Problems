#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1005;
struct edge
{
    int v, w, next;
} G[100005], G2[100005];
int tot,pre[MAXN],t2,p2[MAXN],limit;
void add(int u, int v, int w)
{
    G[tot].v = v;
    G[tot].w = w;
    G[tot].next = pre[u];
    pre[u] = tot++;
    G2[t2].v = u;
    G2[t2].w = w;
    G2[t2].next = p2[v];
    p2[v] = t2++;
}
struct node
{
    int v, d;
    node() {}
    node(int v, int d) : v(v), d(d) {}
    bool operator < (const node &b) const
    {
        if (d != b.d)
        {
            return d > b.d;
        }
        else
        {
            return v > b.v;
        }
    }
};
int n, m, k, dist[MAXN];
bool vis[MAXN];
void dijkstra(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[s] = 0;
    priority_queue<node> que;
    que.push(node(s, 0));
    while (!que.empty())
    {
        node p = que.top();
        que.pop();
        if (vis[p.v])
        {
            continue;
        }
        vis[p.v] = true;
        for (int i = p2[p.v]; ~i; i = G2[i].next)
        {
            int v = G2[i].v, w = G2[i].w;
            if (!vis[v] && p.d + w < dist[v])
            {
                dist[v] = p.d + w;
                que.push(node(v, dist[v]));
            }
        }
    }
}
struct point
{
    int v, h, g;
    point() {}
    point(int v, int h, int g) : v(v), h(h), g(g) {}
    bool operator < (const point & b) const
    {
        return h + g > b.h + b.g;
    }
};
int times[MAXN];
int Astar(int s, int e)
{
    if (dist[s] == INF)
    {
        return -1;
    }
    memset(times, 0, sizeof(times));
    priority_queue<point> Q;
    Q.push(point(s, 0, 0));
    while (!Q.empty())
    {
        point p = Q.top();
        Q.pop();
        ++times[p.v];
        if (times[p.v] == k && p.v == e)
        {
            return p.h + p.g;
        }
        if(p.h + p.g>limit)return -1;
        if (times[p.v] > k)
        {
            continue;
        }
        for (int i = pre[p.v]; ~i; i = G[i].next)
        {
            Q.push(point(G[i].v, p.h + G[i].w, dist[G[i].v]));
        }
    }
    return -1;
}
void init()
{
    tot = t2 = 0;
    memset(pre, -1, sizeof(pre));
    memset(p2, -1, sizeof(p2));
}
int u, v, w, s, e;
int main()
{
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        init();
        scanf("%d %d %d %d", &s, &e, &k, &limit);
        for (int i=1;i<=m;++i)
        {
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w);
        }
        dijkstra(e);
        int ans=Astar(s, e);
        if(ans==-1||ans>limit)
        {
            printf("Whitesnake!\n");
        }
        else
        {
            printf("yareyaredawa\n");
        }
    }
    return 0;
}