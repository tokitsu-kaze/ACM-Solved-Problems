#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=10007;
const ll sz=4;
struct Matrix
{
	ll c[sz+10][sz+10];
	Matrix(){}
	friend Matrix operator *(Matrix a,Matrix b)
	{
		Matrix res;
		mem(res.c,0);
		for(int i=0;i<sz;i++)
		{
			for(int j=0;j<sz;j++)
			{
				for(int k=0;k<sz;k++)
				{
					res.c[i][j]=(res.c[i][j]+a.c[i][k]*b.c[k][j])%mod;
				}
			}
		}
		return res;
	}
};
Matrix matpow2(Matrix a,ll b)
{
	Matrix res=a;
	b--;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
/*
s[i][0] AÅ¼ BÅ¼ 
s[i][1] AÅ¼ BÆæ 
s[i][2] AÆæ BÅ¼ 
s[i][3] AÆæ BÆæ 
s[i][0]=2*s[i-1][0]+1*s[i-1][1]+1*s[i-1][2]+0*s[i-1][3]
s[i][1]=1*s[i-1][0]+2*s[i-1][1]+0*s[i-1][2]+1*s[i-1][3]
s[i][2]=1*s[i-1][0]+0*s[i-1][1]+2*s[i-1][2]+1*s[i-1][3]
s[i][3]=0*s[i-1][0]+1*s[i-1][1]+1*s[i-1][2]+2*s[i-1][3]
2 1 1 0
1 2 0 1
1 0 2 1
0 1 1 2

2 0 0 0
1 0 0 0
1 0 0 0
0 0 0 0
*/
int main()
{
	ll n,i;
	Matrix a,b,ini;
	mem(ini.c,0);
	for(i=0;i<4;i++)
	{
		ini.c[i][i]=2;
	}
	ini.c[0][1]=ini.c[0][2]=1;
	ini.c[1][0]=ini.c[1][3]=1;
	ini.c[2][0]=ini.c[2][3]=1;
	ini.c[3][1]=ini.c[3][2]=1;
	while(~scanf("%lld",&n))
	{
		a=ini;
		mem(b.c,0);
		b.c[0][0]=2;
		b.c[1][0]=b.c[2][0]=1;
		if(n==1)
		{
			puts("2");
			continue;
		}
		a=matpow2(a,n-1);
		a=a*b;
		printf("%lld\n",a.c[0][0]%mod);
	}
	return 0;
}