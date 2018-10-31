#include<bits/stdc++.h>
using namespace std;
const int MAXEDGE=1000005;
const int MAXPOINT=250005;
int n,m,maxp,save_tot;
long long v1,v2,vsum;
int hash1(int x,int y)
{
    return (x-1)*m+y;
}
struct save_edge
{
    int u,v;
    long long val;
    bool in_tree;
}save[MAXEDGE];
bool cmpsave (const save_edge &x,const save_edge &y)
{
    return x.val>y.val;
}
int bcj[MAXPOINT];
void bjc_init()
{
    for(int i=1;i<=maxp;++i)
    {
        bcj[i]=i;
    }
    return;
}
int bcj_findf(int x)
{
    if(x==bcj[x])return x;
    return bcj[x]=bcj_findf(bcj[x]);
}
void bcj_unions(int x,int y)
{
    if(bcj_findf(x)!=bcj_findf(y))
    {
        bcj[bcj_findf(x)]=bcj_findf(y);
    }
    return;
}


struct node
{
	int to,w;
	node(){}
	node(int _to,int _w) :to(_to),w(_w){}
};
int path[2*MAXPOINT],deep[2*MAXPOINT],first[MAXPOINT],dis[MAXPOINT],tot;
int dp[2*MAXPOINT][20];
bool flag[MAXPOINT];
vector<node> mp[MAXPOINT];
void dfs(int x,int h)
{
	int i;
	flag[x]=1;
	path[++tot]=x;
	first[x]=tot;
	deep[tot]=h;
	for(i=0;i<mp[x].size();i++)
	{
		int to=mp[x][i].to;
		if(!flag[to])
		{
			dis[to]=dis[x]+mp[x][i].w;
			dfs(to,h+1);
			path[++tot]=x;
			deep[tot]=h;
		}
	}
}
void ST(int n)
{
	int i,j,x,y;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=i;
	}
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			x=dp[i][j-1];
			y=dp[i+(1<<(j-1))][j-1];
			dp[i][j]=deep[x]<deep[y]?x:y;
		}
	}
}
int query(int l,int r)
{
	int len,x,y;
	len=(int)log2(r-l+1); 
	x=dp[l][len];
	y=dp[r-(1<<len)+1][len];
	return deep[x]<deep[y]?x:y;
}
int LCA(int x,int y)
{
	int l,r,pos;
	l=first[x];
	r=first[y];
	if(l>r) swap(l,r);
	pos=query(l,r);
	return path[pos];
} 
int getdist(int a,int b)
{
	return dis[a]+dis[b]-2*dis[LCA(a,b)];
}
void work(int n)
{
	int i;
	for(i=1;i<=n;i++) dis[i]=flag[i]=0;
	tot=0;
	dfs(1,0);
	ST(2*n-1);
}


int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        save_tot=0;
        vsum=0;
        maxp=n*m;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%*s %lld %*s %lld",&v1,&v2);
                if(i!=n)
                {
                    save[++save_tot].u=hash1(i,j);
                    save[save_tot].v=hash1(i+1,j);
                    save[save_tot].val=v1;
                    save[save_tot].in_tree=false;
                    vsum+=v1;
                }
                if(j!=m)
                {
                    save[++save_tot].u=hash1(i,j);
                    save[save_tot].v=hash1(i,j+1);
                    save[save_tot].val=v2;
                    save[save_tot].in_tree=false;
                    vsum+=v2;
                }
            }
        }
        sort(save+1,save+1+save_tot,cmpsave);
        bjc_init();
        for(int i=1;i<=save_tot;++i)
        {
            if(bcj_findf(save[i].u)!=bcj_findf(save[i].v))
            {
                bcj_unions(save[i].u,save[i].v);
                save[i].in_tree=true;
            }
        }
        for(int i=1;i<=maxp;i++) mp[i].clear();
        for(int i=1;i<=save_tot;i++)
        {
			if(save[i].in_tree)
			{
				mp[save[i].u].push_back(node(save[i].v,1));
				mp[save[i].v].push_back(node(save[i].u,1));
			}
		}
        work(maxp);
        int q;
        scanf("%d",&q);
        int a,b,c,d;
        while(q--)
        {
			scanf("%d%d%d%d",&a,&b,&c,&d);
			printf("%d\n",getdist(hash1(a,b),hash1(c,d)));
		}
    }
    return 0;
}