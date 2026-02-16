#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct Matrix
{
	static const int N=101;
	int n;
	ll c[N][N];
	Matrix(){}
	Matrix(int _n,ll v)
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
		Matrix res(n,LLINF);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				if(c[i][k]==LLINF) continue;
				for(j=0;j<n;j++)
				{
					if(b.c[k][j]==LLINF) continue;
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
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	Matrix mp(n,LLINF);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) scanf("%lld",&mp.c[i][j]);
	}
	auto res=matpow2(mp,k);
	for(i=0;i<n;i++) printf("%lld\n",res.c[i][i]);
	return 0;
}
