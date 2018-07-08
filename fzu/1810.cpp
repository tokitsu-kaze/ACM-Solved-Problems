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
const ll mod=200907;
const ll sz=3;
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
s[i]=s[i-1]+2*s[i-2]+1
1 2 1
1 0 0
0 0 1

2 0 0
1 0 0
1 0 0
*/
int main()
{
	ll n,i;
	Matrix a,b;
	while(~scanf("%lld",&n)&&n)
	{
		mem(a.c,0);
		a.c[0][0]=a.c[0][2]=a.c[1][0]=a.c[2][2]=1;
		a.c[0][1]=2;
		mem(b.c,0);
		b.c[0][0]=2;
		b.c[1][0]=b.c[2][0]=1;
		if(n<=2)
		{
			printf("%lld\n",b.c[2-n][0]);
			continue;
		}
		a=matpow2(a,n-2);
		a=a*b;
		printf("%lld\n",a.c[0][0]%mod);
	}
	return 0;
}