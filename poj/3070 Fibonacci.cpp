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
const ll mod=1e4;
const ll sz=2;
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
int main()
{
	ll t,n;
	Matrix a,b;
	while(~scanf("%lld",&n)&&n>=0)
	{
		if(n==0)
		{
			puts("0");
			continue;
		}
		mem(a.c,0);
		mem(b.c,0);
		a.c[0][0]=a.c[0][1]=a.c[1][0]=1;
		b.c[0][0]=b.c[1][0]=1;
		a=matpow2(a,n-2);
		a=a*b;
		printf("%lld\n",a.c[0][0]%mod);
	}
	return 0;
}