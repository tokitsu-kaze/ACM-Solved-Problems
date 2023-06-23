#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
struct Kuhn_Munkres
{
	#define type ll
	const type inf=LLINF;
	static const int N=505;
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
				w[i][j]=-inf;
			}
		}
	}
	void add_edge(int x,int y,type val){w[x][y]=val;}
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
		int i;
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
			if(w[i][mx[i]]!=-inf) res+=w[i][mx[i]];
		}
		return res;
	}
	#undef type
	#undef inf
}km;
/*
O(n^3)
km.init(n);
km.add_edge(a,b,val); a,b: 1~n
*/
int main()
{
	int n,m,i,a,b,c;
	scanf("%d%d",&n,&m);
	km.init(n);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		km.add_edge(a,b,c);
	}
	printf("%lld\n",km.max_match());
	for(i=1;i<=n;i++) printf("%d%c",km.my[i]," \n"[i==n]);
	return 0;
}
