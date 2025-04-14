#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
struct Gauss
{
	const double eps=1e-7;
	static const int N=105;
	double mp[N][N];
	void init()
	{
		int i,j;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				mp[i][j]=0;
			}
		}
	}
	int gauss(int n,int m)
	{
		int i,j,k,pos,r;
		double tmp;
		r=0;
		for(k=1;k<=m;k++)
		{
			pos=r+1;
			if(pos>n) return -1; // no solution
			for(i=pos+1;i<=n;i++)
			{
				if(fabs(mp[i][k])>fabs(mp[pos][k])) pos=i;
			}
			if(fabs(mp[pos][k])<eps) continue;
			r++;
			swap(mp[pos],mp[r]);
			tmp=mp[r][k];
			for(j=k;j<=m+1;j++) mp[r][j]/=tmp;
			for(i=r+1;i<=n;i++)
			{
				tmp=mp[i][k];
				for(j=k;j<=m+1;j++)
				{
					mp[i][j]-=mp[r][j]*tmp;
				}
			}
		}
		return r;
	}
	double tmp[N];
	int work(int n,int m,int *res)
	{
		int i,j,cnt,mx;
		cnt=gauss(n,m);
		if(cnt==-1) return -1;
		for(i=cnt+1;i<=n;i++)
		{
			if(mp[i][m+1]!=0)
			{
				// no solution
				return -1;
			}
		}
		if(cnt<m)
		{
			// multi solution
			return 1;
		}
		for(i=m;i>=1;i--)
		{
			tmp[i]=mp[i][m+1];
			for(j=i+1;j<=m;j++)
			{
				tmp[i]-=mp[i][j]*tmp[j];
			}
		}
		mx=0;
		for(i=1;i<=m;i++)
		{
			res[i]=tmp[i];
			if(abs(res[i]-tmp[i])>eps) return -1;
			if(res[i]<=0) return -1;
			mx=max(mx,res[i]);
		}
		cnt=0;
		for(i=1;i<=m;i++)
		{
			if(res[i]==mx) cnt++;
		}
		if(cnt>1) return -1;
		return 0;
	}
}gs;
/*
(mp[1][1]*x1) + (mp[1][2]*x2) + ... + (mp[1][m]*xm) = mp[1][m+1]
(mp[2][1]*x1) + (mp[1][2]*x2) + ... + (mp[2][m]*xm) = mp[2][m+1]
...
(mp[n][1]*x1) + (mp[n][2]*x2) + ... + (mp[n][m]*xm) = mp[n][m+1]

x x x x | x
0 x x x | x
0 0 x x | x
0 0 0 x | x

O(n*m^2) m<=n

gs.work(n,m,res); mp[1..n][1..m+1], res[1..m]

-1: no solution
0 : one solution
1 : multi solution
*/
vector<int> id[MAX];
int w[MAX],res[MAX];
int main()
{
	int n,m,i,ban,mx,ans,cnt,tot;
	scanf("%d",&n);
	for(i=1;i<=n+1;i++)
	{
		scanf("%d",&m);
		id[i].resize(m);
		for(auto &it:id[i]) scanf("%d",&it);
		scanf("%d",&w[i]);
	}
	ans=-1;
	cnt=0;
	for(ban=1;ban<=n+1;ban++)
	{
		gs.init();
		tot=0;
		for(i=1;i<=n+1;i++)
		{
			if(i==ban) continue;
			tot++;
			for(auto &it:id[i]) gs.mp[tot][it]+=1;
			gs.mp[tot][n+1]=w[i];
		}
		if(gs.work(n,n,res)!=0) continue;
		cnt++;
		mx=0;
//		cout<<ban<<endl;
		for(i=1;i<=n;i++)
		{
			if(res[i]>mx)
			{
				mx=res[i];
				ans=i;
			}
//			printf("%d%c",res[i]," \n"[i==n]);
		}
	}
	if(cnt!=1) puts("illegal");
	else printf("%d\n",ans);
	return 0;
}
