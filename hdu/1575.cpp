////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-29 20:24:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1575
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1700KB
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
const int MAX=10+10;
const ll mod=9973;
ll n;
struct Matrix
{
	ll c[MAX][MAX];
	Matrix(){}
	void input()
	{
		mem(c,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%I64d",&c[i][j]);
			}
		}
	}
	friend Matrix operator *(Matrix a,Matrix b)
	{
		Matrix res;
		mem(res.c,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
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
	Matrix mat,res;
	ll i,j,ans,t,k;
	while(~scanf("%I64d",&t))
	{
		while(t--)
		{
			scanf("%I64d%I64d",&n,&k);
			mat.input();
			res=matpow2(mat,k);
			ans=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(i==j)
					{
						ans+=res.c[i][j];
						ans%=mod;
					}
				}
			}
			printf("%I64d\n",ans%mod);
		}
	}
	return 0;
}