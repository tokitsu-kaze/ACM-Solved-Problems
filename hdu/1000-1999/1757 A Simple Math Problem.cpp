////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-29 23:00:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1757
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1712KB
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
const int MAX=11+10;
const ll mod=9973;
ll m;
struct Matrix
{
	ll c[MAX][MAX];
	Matrix(){}
	friend Matrix operator *(Matrix a,Matrix b)
	{
		Matrix res;
		mem(res.c,0);
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				for(int k=0;k<10;k++)
				{
					res.c[i][j]=(res.c[i][j]+a.c[i][k]*b.c[k][j])%m;
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
	Matrix temp,a;
	ll i,j,k,n;
	while(~scanf("%I64d%I64d",&n,&m))
	{
		mem(a.c,0);
		mem(temp.c,0);
		for(i=0;i<10;i++)
		{
			scanf("%d",&temp.c[0][i]);
			a.c[i][0]=9-i;
		}
		if(n<10)
		{
			printf("%I64d\n",n);
			continue;
		}
		for(i=1;i<10;i++)
		{
			temp.c[i][i-1]=1;
		}
		temp=matpow2(temp,n-9);
		a=temp*a;
		printf("%I64d\n",a.c[0][0]%m);
	}
	return 0;
}