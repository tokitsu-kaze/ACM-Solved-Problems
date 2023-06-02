////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-10 14:56:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2371
////Problem Title: 
////Run result: Accept
////Run time:452MS
////Run memory:2088KB
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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=1e6+10;
const int sz=80;
int n;
struct Matrix
{
	int c[sz+10][sz+10];
	Matrix(){}
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
					res.c[i][j]=res.c[i][j]+a.c[i][k]*b.c[k][j];
				}
			}
		}
		return res;
	}
};
//¾ØÕó¿ìËÙÃÝ 
Matrix matpow2(Matrix a,int b)
{
	Matrix res;
	mem(res.c,0);
	for(int i=0;i<n;i++)
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
	int m,x,i,j;
	Matrix a,temp;
	char c[111];
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		mem(a.c,0);
		mem(temp.c,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			a.c[i-1][0]=i;
			temp.c[x-1][i-1]=1;
		}
		getchar();
		gets(c);
		a=matpow2(temp,m)*a;
		for(i=0;i<n;i++)
		{
			putchar(c[a.c[i][0]-1]);
		}
		puts("");
	}
	return 0;
}