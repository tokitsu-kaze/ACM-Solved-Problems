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
const int n=9;
int mp[11][11],xx[88],yy[88],ok;
int flagx[11][11],flagy[11][11],flag[11][11];
void dfs(int pos)
{
	if(ok) return;
	if(pos==-1)
	{
		ok=1;
		return;
	}
	int x,y,i;
	x=xx[pos];
	y=yy[pos];
	if(mp[x][y])
	{
		dfs(pos-1);
		return;
	}
	for(i=1;i<=9;i++)
	{
		if(flagx[x][i]) continue;
		if(flagy[y][i]) continue;
		if(flag[id[x][y]][i]) continue;
		mp[x][y]=i;
		flagx[x][i]=flagy[y][i]=flag[id[x][y]][i]=1;
		dfs(pos-1);
		if(ok) return;
		mp[x][y]=0;
		flagx[x][i]=flagy[y][i]=flag[id[x][y]][i]=0;
	}
}
int main()
{
	int i,j,tot;
	memset(flagx,0,sizeof flagx);
	memset(flagy,0,sizeof flagy);
	memset(flag,0,sizeof flag);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&mp[i][j]);
			tot++;
			xx[tot]=i;
			yy[tot]=j;
			if(mp[i][j])
			{
				flagx[i][mp[i][j]]=1;
				flagy[j][mp[i][j]]=1;
				flag[id[i][j]][mp[i][j]]=1;
			}
		}
	}
	ok=0;
	dfs(81);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d%c",mp[i][j]," \n"[j==n]);
		}
	}
	
	return 0;
}
