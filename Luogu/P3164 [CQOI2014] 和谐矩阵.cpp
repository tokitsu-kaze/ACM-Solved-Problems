#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
struct Gauss
{
	static const int N=1601;
	bitset<N> mp[N];
	void init()
	{
		for(int i=0;i<N;i++) mp[i].reset();
	}
	int gauss(int n,int m)
	{
		int i,j,k,pos,r;
		r=0;
		for(k=1;k<=m;k++)
		{
			pos=r+1;
			if(pos>n) return -1; // no solution
			while(pos<n&&!mp[pos][k]) pos++;
			if(!mp[pos][k]) continue;
			r++;
			swap(mp[pos],mp[r]);
			for(i=r+1;i<=n;i++)
			{
				if(mp[i][k]) mp[i]^=mp[r];
			}
		}
		return r;
	}
	int work(int n,int m,int *res)
	{
		int i,j,cnt;
		cnt=gauss(n,m);
		if(cnt==-1) return -1;
		for(i=cnt+1;i<=n;i++)
		{
			if(mp[i][m+1])
			{
				// no solution
				return -1;
			}
		}
		if(cnt<m)
		{
			// multi solution
			
			/*
			1 1 0 0 0      1 1 0 0 0
			0 1 1 0 0  ->  0 1 1 0 0
			0 0 0 1 0      0 0 0 0 0
			0 0 0 0 0      0 0 0 1 0
			*/
			for(i=1;i<=n;i++)
			{
				if(!mp[i][i])
				{
					for(j=n;j>i;j--) swap(mp[j],mp[j-1]);
				}
			}
			
			//make solution
			for(i=m;i;i--)
			{
				res[i]=mp[i][m+1];
				for(j=i+1;j<=m;j++) res[i]^=(mp[i][j]*res[j]);
				if(mp[i][i]==0) res[i]=1;
			}
			
			return 1;
		}
		for(i=1;i<=m;i++) res[i]=mp[i][m+1];
		return 0;
	}
}gs;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int id[44][44],res[40*40+10];
int main()
{
	int n,m,i,j,k,x,y,tot;
	scanf("%d%d",&n,&m);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) id[i][j]=++tot;
	}
	gs.init();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			gs.mp[id[i][j]][id[i][j]]=1;
			for(k=0;k<4;k++)
			{
				x=i+dir[k][0];
				y=j+dir[k][1];
				if(x<1||x>n||y<1||y>m) continue;
				gs.mp[id[i][j]][id[x][y]]=1;
			}
		}
	}
	gs.work(n*m,n*m,res);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%d%c",res[id[i][j]]," \n"[j==m]);
		}
	}
	return 0;
}
