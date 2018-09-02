#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1000000007;
struct Matrix
{
	ll c[16][16],n;
	Matrix(){}
	Matrix(ll a,ll v=0)
	{
		int i,j;
		n=a;
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
		Matrix res(n);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				if(!c[i][k]) continue;
				for(j=0;j<n;j++)
				{
					res.c[i][j]=(res.c[i][j]+c[i][k]*b.c[k][j])%mod;
				}
			}
		}
		return res;
	}
};
Matrix matpow2(Matrix a,ll b)
{
	Matrix res(a.n);
	for(int i=0;i<a.n;i++)
	{
		res.c[i][i]=1;
	}
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
const int tmp[16][16]=
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,
0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,
0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,
1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1};
int main()
{
	int i,j;
	Matrix a,res;
	a.n=16;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			a.c[i][j]=tmp[i][j];
		}
	}
	ll n;
	while(~scanf("%lld",&n))
	{
		res=matpow2(a,n+1);
		printf("%lld\n",res.c[15][0]);
	}
	return 0;
}