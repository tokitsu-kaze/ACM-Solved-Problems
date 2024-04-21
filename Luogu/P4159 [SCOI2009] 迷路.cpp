#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const ll mod=2009;
struct Matrix
{
	static const int N=115;
	int n;
	ll c[N][N];
	Matrix(){}
	Matrix(int _n,ll v=0)
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
	void init_identity_matrix() {for(int i=0;i<n;i++) c[i][i]=1;}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				if(!c[i][k]) continue;
				for(j=0;j<n;j++)
				{
					res.c[i][j]+=c[i][k]*b.c[k][j];
					if(res.c[i][j]>=mod) res.c[i][j]%=mod;
				}
			}
		}
		return res;
	}
};
Matrix matqpow(Matrix a,ll b)
{
	Matrix res(a.n);
	res.init_identity_matrix();
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int id[12][12];
int main()
{
	int n,t,i,j,tot;
	char s[12];
	Matrix tmp(100,0);
	scanf("%d%d",&n,&t);
	tot=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<10;j++)
		{
			id[i][j]=++tot;
			if(j) tmp.c[id[i][j-1]][id[i][j]]=1;
		}
	}
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		for(j=0;j<n;j++)
		{
			if(s[j]-'0'==0) continue;
			tmp.c[id[i][s[j]-'0'-1]][id[j][0]]=1;
		}
	}
	tmp=matqpow(tmp,t);
	printf("%d\n",tmp.c[id[0][0]][id[n-1][0]]);
	return 0;
}
