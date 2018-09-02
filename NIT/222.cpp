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
const int MAX=1e7+10;
const int mod=1e3;
const ll sz=3;
struct Matrix
{
	int c[sz+1][sz+1];
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
Matrix matpow2(Matrix a,int b)
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
int mp[MAX];
int main()
{
	int k;
	Matrix a,temp,ans;
	mem(a.c,0);
	a.c[0][0]=2;
	a.c[1][0]=1;
	a.c[2][0]=1;
	mem(temp.c,0);
	temp.c[0][0]=temp.c[0][1]=temp.c[1][1]=temp.c[2][1]=1;
	temp.c[0][2]=temp.c[1][2]=3;
	mem(mp,0);
	while(~scanf("%d",&k))
	{
		if(k<=2)
		{
			if(k<=0) puts("0");
			else if(k==1) puts("1");
			else if(k==2) puts("2");
			continue;
		}
		if(k<=1e7&&mp[k])
		{
			printf("%d\n",mp[k]);
			continue;
		}
		ans=matpow2(temp,k-2)*a;
		printf("%d\n",ans.c[0][0]%mod);
		if(k<=1e7) mp[k]=ans.c[0][0]%mod;
	}
	return 0;
} 