#include <bits/stdc++.h>
using namespace std;
struct Gauss
{
	bitset<1010> mp[2010];
	int gauss_jordan(int n,int m,int &ans)
	{
		int i,j,k,pos,r;
		r=0;
		for(k=1;k<=m;k++)
		{
			pos=r+1;
			if(pos>n) return -1; // no solution
			while(pos<n&&!mp[pos][k]) pos++;
			if(!mp[pos][k]) continue;
			ans=max(ans,pos);
			r++;
			swap(mp[pos],mp[r]);
			for(i=1;i<=n;i++)
			{
				if(i!=r&&mp[i][k]) mp[i]^=mp[r];
			}
		}
		return r;
	}
	int work(int n,int m,int *res,int &ans)
	{
		int i,j,cnt;
		cnt=gauss_jordan(n,m,ans);
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
			return 1;
		}
		for(i=1;i<=m;i++) res[i]=mp[i][m+1];
		return 0;
	}
}gs;
/*
(mp[1][1]*x1) xor (mp[1][2]*x2) xor ... xor (mp[1][m]*xm) = mp[1][m+1]
(mp[2][1]*x1) xor (mp[1][2]*x2) xor ... xor (mp[2][m]*xm) = mp[2][m+1]
...
(mp[n][1]*x1) xor (mp[n][2]*x2) xor ... xor (mp[n][m]*xm) = mp[n][m+1]

a:0/1  x:0/1

x 0 0 0 | x
0 x 0 0 | x
0 0 x 0 | x
0 0 0 x | x


O((n*m^2)/64)

gs.work(n,m,mp,res); mp[1..n][1..m+1], res[1..m]

-1: no solution
0 : one solution
1 : multi solution
*/
int res[1010];
int main()
{
	int n,m,i,j,x,ans;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m+1;j++)
		{
			scanf("%1d",&x);
			gs.mp[i][j]=x;
		}
	}
	if(gs.work(n,m,res,ans)==1) puts("Cannot Determine");
	else
	{
		printf("%d\n",ans);
		for(i=1;i<=m;i++)
		{
			if(res[i]) puts("?y7M#");
			else puts("Earth");
		}
	}
	return 0;
}
