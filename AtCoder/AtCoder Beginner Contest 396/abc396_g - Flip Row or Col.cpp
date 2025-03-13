#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5;
const int mod=998244353;
namespace FWT
{
	const int p=998244353;
	const ll inv2=(p+1)/2;
	void fwt(vector<int> &a,int n,int f,int v)
	{  
		for(int d=1;d<n;d<<=1)
		{
			for(int m=d<<1,i=0;i<n;i+=m)
			{
				for(int j=0;j<d;j++)
				{  
					ll x=a[i+j],y=a[i+j+d];
					if(v==1)
					{
						if(f==1) a[i+j]=(x+y)%p,a[i+j+d]=(x-y+p)%p;//xor
					}
					else
					{
						if(f==1) a[i+j]=(x+y)*inv2%p,a[i+j+d]=(x-y+p)%p*inv2%p;//xor
					}
				}
			}
		}
	}
	
	vector<int> XOR(vector<int> a,vector<int> b)
	{
		int n,len;
		n=a.size();
		for(len=1;len<n;len<<=1);
		a.resize(len,0);
		b.resize(len,0);
		fwt(a,len,1,1);
		fwt(b,len,1,1);
		for(int i=0;i<len;i++) a[i]=1ll*a[i]*b[i]%p;
		fwt(a,len,1,-1);
		return a;
	}
}
int main()
{
	int n,m,i,j,now,x,ans;
	scanf("%d%d",&n,&m);
	vector<int> cnt(1<<m,0),tmp(1<<m,0);
	for(i=1;i<=n;i++)
	{
		now=0;
		for(j=0;j<m;j++)
		{
			scanf("%1d",&x);
			now|=(x<<j);
		}
		cnt[now]++;
	}
	for(i=0;i<(1<<m);i++)
	{
		tmp[i]=__builtin_popcount(i);
		tmp[i]=min(tmp[i],m-tmp[i]);
	}
	vector<int> res=FWT::XOR(cnt,tmp);
	ans=1e9;
	for(i=0;i<(1<<m);i++) ans=min(ans,res[i]);
	printf("%d\n",ans);
	return 0;
}

