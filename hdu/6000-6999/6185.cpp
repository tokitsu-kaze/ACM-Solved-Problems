////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-31 17:14:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6185
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:1680KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
const int sz=4;
struct Matrix
{
	ll c[sz][sz];
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
	ll n;
	Matrix a,temp,ans;
	mem(a.c,0);
	a.c[0][0]=36;
	a.c[1][0]=11;
	a.c[2][0]=5;
	a.c[3][0]=1;
	mem(temp.c,0);
	temp.c[0][0]=temp.c[0][2]=temp.c[1][0]=temp.c[2][1]=temp.c[3][2]=1;
	temp.c[0][1]=5;
	temp.c[0][3]=-1;
	while(~scanf("%lld",&n))
	{
		if(n<=4)
		{
			printf("%lld\n",a.c[4-n][0]);
			continue;
		}
		ans=temp;
		ans=matpow2(ans,n-4)*a;
		printf("%lld\n",(ans.c[0][0]+mod)%mod);
	}
	return 0;
}