#include <bits/stdc++.h>
using namespace std;
struct Gauss
{
	const double eps=1e-7;
	double mp[55][55];
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
	int work(int n,int m,double *res)
	{
		int i,j,cnt;
		cnt=gauss(n,m);
		if(cnt==-1) return -1;
		for(i=cnt+1;i<=n;i++)
		{
			if(fabs(mp[i][m+1])>eps)
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
		res[m]=mp[m][m+1];
		for(i=m-1;i>=1;i--)
		{
			res[i]=mp[i][m+1];
			for(j=i+1;j<=m;j++)
			{
				res[i]-=mp[i][j]*res[j];
			}
		}
		return 0;
	}
}gs;
/*
gs.work(n,m,mp,res); mp[1..n][1..m+1], res[1..m]

-1: no solution
0 : one solution
1 : multi solution
*/
double ans[105];
int main()
{
	int n,i,j,res;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			scanf("%lf",&gs.mp[i][j]);
		}
	}
	res=gs.work(n,n,ans);
	if(res==-1)
	{
		puts("-1");
		return 0;
	}
	if(res==1)
	{
		puts("0");
		return 0;
	}
	for(i=1;i<=n;i++) printf("x%d=%.2f\n",i,ans[i]);
	return 0;
}
/*
3
0 1 1 2
0 0 3 9
0 0 5 15
*/
