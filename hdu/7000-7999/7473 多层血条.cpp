#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char mp[55][805];
int main()
{
	int t,n,m,hp,dmg,i,j,k,r,lst;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&hp,&dmg);
		mp[0][0]=mp[0][m+1]='+';
		mp[n+1][0]=mp[n+1][m+1]='+';
		k=hp/m;
		r=hp%m;
		if(r==0)
		{
			if(k>0)
			{
				k--;
				r+=m;
			}
		}
		for(i=1;i<=m;i++)
		{
			mp[0][i]=mp[n+1][i]='-';
			mp[1][i]=(k-1)%5+'A';
			if(i<=r) mp[1][i]++;
			if(mp[1][i]=='F') mp[1][i]='A';
			if(hp<m && i>hp) mp[1][i]=' ';
		}
		lst=r;
		for(i=lst;i;i--)
		{
			if(dmg==0) break;
			mp[1][i]='.';
			dmg--;
		}
		for(i=m;i>lst;i--)
		{
			if(dmg==0) break;
			if(mp[1][i]==' ') break;
			mp[1][i]='.';
			dmg--;
		}
		for(i=1;i<=n;i++)
		{
			mp[i][0]=mp[i][m+1]='|';
			for(j=1;j<=m;j++) mp[i][j]=mp[1][j];
		}
		for(i=0;i<=n+1;i++)
		{
			mp[i][m+2]='\0';
			puts(mp[i]);
		}
	}
	return 0;
}
/*
100
2 5 4 2
1 10 49 1
1 10 52 0
1 10 52 5
1 10 52 50
2 5 31 0
1 3 21 0
1 3 22 0
*/
