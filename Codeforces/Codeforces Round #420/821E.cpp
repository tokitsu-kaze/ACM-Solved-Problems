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
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
const int sz=16;
struct Matrix
{
	ll c[sz+5][sz+5];
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
	ll n,k,a,b,c,i,j,flag;
	Matrix ans,temp;
	while(~scanf("%lld%lld",&n,&k))
	{
		flag=0;
		mem(ans.c,0);
		ans.c[0][0]=1;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			if(flag) continue;
			for(j=c+1;j<sz;j++)
			{
				ans.c[j][0]=0;
			}
			b=min(b,k);
			if(b==k) flag=1;
			mem(temp.c,0);
			for(j=0;j<=c;j++)
			{
				temp.c[j][j]=1;
				if(j-1>=0) temp.c[j-1][j]=1;
				if(j+1<=c) temp.c[j+1][j]=1;
			}
			temp=matpow2(temp,b-a);
			ans=ans*temp;
		}
		printf("%lld\n",ans.c[0][0]%mod);
	}
	return 0;
}