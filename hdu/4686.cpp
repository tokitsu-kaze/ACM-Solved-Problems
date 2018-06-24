////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-30 16:20:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4686
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:1688KB
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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
const ll sz=5;
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
	Matrix ans,temp;
	ll k,a,x1,y1,b,x2,y2;
	while(~scanf("%lld",&k))
	{
		scanf("%lld%lld%lld%lld%lld%lld",&a,&x1,&y1,&b,&x2,&y2);
		if(k==0)
		{
			puts("0");
			continue;
		}
		x1%=mod;
		y1%=mod;
		x2%=mod;
		y2%=mod;
		a%=mod;
		b%=mod;
		mem(temp.c,0);
		temp.c[0][0]=1;
		temp.c[0][1]=temp.c[1][1]=x1*x2%mod;
		temp.c[0][2]=temp.c[1][2]=x1*y2%mod;
		temp.c[0][3]=temp.c[1][3]=x2*y1%mod;
		temp.c[0][4]=temp.c[1][4]=y1*y2%mod;
		temp.c[2][2]=x1;
		temp.c[3][3]=x2;
		temp.c[2][4]=y1;
		temp.c[3][4]=y2;
		temp.c[4][4]=1;
		mem(ans.c,0);
		ans.c[0][0]=a*b%mod;
		ans.c[1][0]=a*b%mod;
		ans.c[2][0]=a;
		ans.c[3][0]=b;
		ans.c[4][0]=1;
		ans=matpow2(temp,k-1)*ans;
		printf("%lld\n",ans.c[0][0]);
	}
	return 0;
}