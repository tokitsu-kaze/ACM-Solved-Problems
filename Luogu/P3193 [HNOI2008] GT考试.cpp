#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
int mod;
struct Matrix
{
	static const int N=22;
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
	void print()
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%lld%c",c[i][j]," \n"[j+1==n]);
			}
		}
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
struct KMP_Automaton
{
	#define type char
	static const int K=10;
	int nex[MAX],len,fail[MAX][K];
	type t[MAX];
	int get_id(char c){return c-'0';} //may need change
	void get_next(type *s,int n)
	{
		int i,j,k;
		len=n;
		for(i=1;i<=len;i++) t[i]=s[i];
		t[len+1]=0;
		nex[0]=nex[1]=0;
		j=0;
		for(i=2;i<=len;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			nex[i]=j;
		}
		memset(fail[0],0,sizeof fail[0]);
		for(i=0;i<=len;i++)
		{
			for(k=0;k<K;k++) fail[i][k]=fail[nex[i]][k];
			if(i+1<=len) fail[i][get_id(s[i+1])]=i;
		}
	}
	vector<int> match(type *s,int n)
	{
		int i,j;
		vector<int> res;
		for(i=1,j=0;i<=n;i++)
		{
			j=fail[j][get_id(s[i])];
			if(t[j+1]==s[i]) j++;
			if(j==len)
			{
				res.push_back(i-len+1);
				j=nex[j];
			}
		}
		return res;
	}
	Matrix get_mat()
	{
		int i,j,to;
		Matrix a(len,0);
		for(i=0;i<len;i++)
		{
			for(j=0;j<K;j++)
			{
				to=fail[i][j];
				if(get_id(t[to+1])==j) to++;
				a.c[i][to]++;
			}
		}
		return a;
	}
	#undef type
}kmpam;
/*
kmpam.get_next(t,len); // t[1..len]
kmpam.match(s,n); // s[1..n] return all pos t in s 
*/
int main()
{
	int n,m,i,ans;
	char s[22];
	scanf("%d%d%d",&n,&m,&mod);
	scanf("%s",s+1);
	kmpam.get_next(s,m);
	auto res=kmpam.get_mat();
//	res.print();
	res=matqpow(res,n);
	ans=0;
	for(i=0;i<res.n;i++) ans=(ans+res.c[0][i])%mod;
	printf("%d\n",ans);
	return 0;
}
/*
1000000 5 10007
16121
*/
