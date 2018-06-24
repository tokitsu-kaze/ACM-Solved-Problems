////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-05 06:56:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2157
////Problem Title: 
////Run result: Accept
////Run time:249MS
////Run memory:1708KB
//////////////////System Comment End//////////////////
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
const ll mod=1000;
ll sz;
struct Matrix
{
	ll c[22][22];
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
	Matrix res;
	mem(res.c,0);
	for(int i=0;i<sz;i++)
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
int main()
{
	ll x,y,k,m,t;
	Matrix a,b;
	while(~scanf("%I64d%I64d",&sz,&m)&&sz+m)
	{
		mem(a.c,0);
		while(m--)
		{
			scanf("%I64d%I64d",&x,&y);
			a.c[x][y]=1;
		}
		scanf("%I64d",&t);
		while(t--)
		{
			scanf("%I64d%I64d%I64d",&x,&y,&k);
			b=a;
			b=matpow2(b,k);
			printf("%I64d\n",b.c[x][y]%mod);
		}
	}
	return 0;
}