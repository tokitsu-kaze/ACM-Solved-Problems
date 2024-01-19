#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
const ll mod=1e9+7;
struct Matrix
{
	static const int N=101;
	int n;
	int c[N][N];
	Matrix(){}
	Matrix(int _n,int v)
	{
		int i,j;
		n=_n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=v;
			}
		}
	}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n,INF);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				if(c[i][k]==INF) continue;
				for(j=0;j<n;j++)
				{
					if(b.c[k][j]==INF) continue;
					res.c[i][j]=min(res.c[i][j],c[i][k]+b.c[k][j]);
				}
			}
		}
		return res;
	}
};
Matrix matpow2(Matrix a,int b)
{
	Matrix res=a;
	b--;
	while(b>0)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main()
{
	int n,m,s,t,a,b,c,i,id[1005],tot;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	Matrix mp(m,INF);
	tot=0;
	for(i=1;i<=1000;i++) id[i]=-1;
	if(id[s]==-1) id[s]=tot++;
	if(id[t]==-1) id[t]=tot++;
	s=id[s];
	t=id[t];
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&c,&a,&b);
		if(id[a]==-1) id[a]=tot++;
		if(id[b]==-1) id[b]=tot++;
		a=id[a];
		b=id[b];
		mp.c[a][b]=mp.c[b][a]=min(mp.c[a][b],c);
	}
	printf("%d\n",matpow2(mp,n).c[s][t]);
	return 0;
}
