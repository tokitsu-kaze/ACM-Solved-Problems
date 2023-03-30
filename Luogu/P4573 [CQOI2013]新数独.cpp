#include <bits/stdc++.h>
using namespace std;
int id[11][11] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
	{0, 7, 7, 7, 8, 8, 8, 9, 9, 9}
};
int dir[4][2]={0,-1,0,1,-1,0,1,0};
char rel[11][11][5];
const int n=9;
int mp[11][11],xx[88],yy[88],ok;
int flagx[11][11],flagy[11][11],flag[11][11];
int ck(int x,int y,int v)
{
	int i,nx,ny;
	for(i=0;i<4;i++)
	{
		nx=x+dir[i][0];
		ny=y+dir[i][1];
		if(nx<1 || nx>n || ny<1 || ny>n) continue;
		if(!mp[nx][ny]) continue;
		if(id[x][y]!=id[nx][ny]) continue;
		char tmp=rel[x][y][i];
		if(i==0)
		{
			if(tmp=='<' && v<=mp[nx][ny]) return 0;
			if(tmp=='>' && v>=mp[nx][ny]) return 0;
		}
		else if(i==1)
		{
			if(tmp=='<' && v>=mp[nx][ny]) return 0;
			if(tmp=='>' && v<=mp[nx][ny]) return 0;
		}
		else if(i==2)
		{
			if(tmp=='^' && v<=mp[nx][ny]) return 0;
			if(tmp=='v' && v>=mp[nx][ny]) return 0;
		}
		else if(i==3)
		{
			if(tmp=='^' && v>=mp[nx][ny]) return 0;
			if(tmp=='v' && v<=mp[nx][ny]) return 0;
		}
	}
	return 1;
}
void dfs(int pos)
{
	if(ok) return;
	if(pos==82)
	{
		ok=1;
		return;
	}
	int x,y,i;
	x=xx[pos];
	y=yy[pos];
	if(mp[x][y])
	{
		dfs(pos+1);
		return;
	}
	for(i=1;i<=9;i++)
	{
		if(flagx[x][i]) continue;
		if(flagy[y][i]) continue;
		if(flag[id[x][y]][i]) continue;
		if(!ck(x,y,i)) continue;
		mp[x][y]=i;
		flagx[x][i]=flagy[y][i]=flag[id[x][y]][i]=1;
		dfs(pos+1);
		if(ok) return;
		mp[x][y]=0;
		flagx[x][i]=flagy[y][i]=flag[id[x][y]][i]=0;
	}
}
int main()
{
	char ss[2];
	int i,j,tot;
	memset(flagx,0,sizeof flagx);
	memset(flagy,0,sizeof flagy);
	memset(flag,0,sizeof flag);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mp[i][j]=0;
			tot++;
			xx[tot]=i;
			yy[tot]=j;
			if(j%3==0) continue;
			scanf("%s",ss);
			rel[i][j][1]=rel[i][j+1][0]=ss[0];
		}
		if(tot%27==0) continue;
		for(j=1;j<=n;j++)
		{
			scanf("%s",ss);
			rel[i][j][3]=rel[i+1][j][2]=ss[0];
		}
	}
	ok=0;
	dfs(1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d%c",mp[i][j]," \n"[j==n]);
		}
	}
	
	return 0;
}
