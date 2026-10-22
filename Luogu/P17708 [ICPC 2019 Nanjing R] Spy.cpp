#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=400+10;
struct Kuhn_Munkres
{
	#define type int
	const type inf=INF;
	static const int N=MAX;
	int n,mx[N],my[N],pre[N];
	type slk[N],lx[N],ly[N],w[N][N];
	bool vx[N],vy[N];
	void init(int _n)
	{
		n=_n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				/*
				- 允许不完美匹配, 虚边边权=0
				- 不允许不完美匹配, 虚边边权=-inf,
				  这样求出来的匹配会使虚边最少, 
				  如果发现不得不选择虚边，就无解
				*/
				w[i][j]=0;
			}
		}
	}
	void add_edge(int x,int y,type val)
	{
		// 需要注意是否有重边，以及边权为负是否必须匹配
		w[x][y]=val;
	}
	void match(int y){while(y) swap(y,mx[my[y]=pre[y]]);}
	void bfs(int x)
	{
		int i,y;
		type d;
		for(i=1;i<=n;i++)
		{
			vx[i]=vy[i]=pre[i]=0;
			slk[i]=inf;
		}
		queue<int> q;
		q.push(x);
		vx[x]=1;
		while(1)
		{
			while(!q.empty())
			{
				x=q.front();
				q.pop();
				for(y=1;y<=n;y++)
				{
					d=lx[x]+ly[y]-w[x][y];
					if(!vy[y]&&d<=slk[y])
					{
						pre[y]=x;
						if(!d)
						{
							if(!my[y]) return match(y);
							q.push(my[y]);
							vx[my[y]]=1;
							vy[y]=1;
						}
						else slk[y]=d;
					}
				}
			}
			d=inf+1;
			for(i=1;i<=n;i++)
			{
				if(!vy[i]&&slk[i]<d)
				{
					d=slk[i];
					y=i;
				}
			}
			for(i=1;i<=n;i++)
			{
				if(vx[i]) lx[i]-=d;
				if(vy[i]) ly[i]+=d;
				else slk[i]-=d;
			}
			if(!my[y]) return match(y);
			q.push(my[y]);
			vx[my[y]]=1;
			vy[y]=1;
		}
	}
	type max_match()
	{
		int i,j;
		type res;
		for(i=1;i<=n;i++)
		{
			mx[i]=my[i]=ly[i]=0;
			lx[i]=*max_element(w[i]+1,w[i]+n+1);
		}
		for(i=1;i<=n;i++) bfs(i);
		res=0;
		for(i=1;i<=n;i++)
		{
			// 不允许不完美匹配可能要判断无解 
			res+=w[i][mx[i]];
		}
		return res;
	}
	#undef type
}km;
/*
O(n^3)
km.init(n);
km.add_edge(a,b,val); a,b: 1~n
*/
ll a[MAX],b[MAX],c[MAX];
int p[MAX],id[MAX],sum[MAX];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	for(i=1;i<=n;i++) scanf("%lld",&b[i]);
	for(i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+1+n,[&](int x,int y){
		return a[x]<a[y];
	});
	sum[0]=0;
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+p[id[i]];
	sort(a+1,a+1+n);
	km.init(n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			km.add_edge(i,j,sum[lower_bound(a+1,a+1+n,b[i]+c[j])-a-1]);
		}
	}
	printf("%d\n",km.max_match());
	return 0;
}
