////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-24 21:57:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6172
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e3+10;
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
	ll n,t;
	Matrix a,temp,ans;
	mem(a.c,0);
	a.c[0][0]=1255;
	a.c[0][1]=197;
	a.c[0][2]=31;
	mem(temp.c,0);
	temp.c[0][0]=4;
	temp.c[1][0]=17;
	temp.c[2][0]=-12;
	temp.c[0][1]=temp.c[1][2]=1;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n<=4)
		{
			printf("%lld\n",a.c[0][4-n]);
			continue;
		}
		ans=a;
		ans=ans*matpow2(temp,n-4);
		printf("%lld\n",(ans.c[0][0]+mod)%mod);
	}
	return 0;
}