////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-30 13:07:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6030
////Problem Title: 
////Run result: Accept
////Run time:639MS
////Run memory:1692KB
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
const ll mod=1e9+7;
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
Matrix matpow2(Matrix a,ll b)//¾ØÕó¿ìËÙÃÝ 
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
//s[i]=s[i-1]+s[i-3]
//s[2]=3 s[3]=4 s[4]=6 s[5]=9
int main()
{
	ll t,n;
	Matrix a,b;
	scanf("%I64d",&t);
	{
		while(t--)
		{
			scanf("%I64d",&n);
			mem(a.c,0);
			a.c[0][0]=a.c[0][2]=a.c[1][0]=a.c[2][1]=1;
			mem(b.c,0);
			b.c[0][0]=9;
			b.c[1][0]=6;
			b.c[2][0]=4;
			if(n<=5)
			{
				if(n==2) puts("3");
				else if(n==3) puts("4");
				else if(n==4) puts("6");
				else if(n==5) puts("9");
				continue;
			}
			a=matpow2(a,n-5);
			a=a*b;
			printf("%I64d\n",a.c[0][0]%mod);
		}
	}
	return 0;
}