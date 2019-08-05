////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-05 06:19:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2276
////Problem Title: 
////Run result: Accept
////Run time:717MS
////Run memory:2924KB
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
const ll mod=2;
ll sz;
struct Matrix
{
	ll c[111][111];
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
	ll i,k;
	char c[111];
	Matrix a,b;
	while(~scanf("%I64d %s",&k,c))
	{
		sz=strlen(c);
		mem(a.c,0);
		for(i=0;i<sz;i++)
		{
			a.c[i][i]=a.c[i][i-1<0?sz-1:i-1]=1;
		}
		mem(b.c,0);
		for(i=0;i<sz;i++)
		{
			b.c[i][0]=c[i]-'0';
		}
		a=matpow2(a,k);
		a=a*b;
		for(i=0;i<sz;i++)
		{
			printf("%I64d",a.c[i][0]%mod);
		}
		puts("");
	}
	return 0;
}