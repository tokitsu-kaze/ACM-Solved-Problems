#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=2e6+10;
namespace NTT
{
	const int g=3;
	const int p=998244353;
	int wn[35];
	int qpow(int a,int b)
	{
		int res=1;
		while(b>0)
		{
			if(b&1) res=1ll*res*a%p;
			a=1ll*a*a%p;
			b>>=1;
		}
		return res;
	}
	void getwn()
	{
		assert(p==mod);
		for(int i=0;i<25;i++) wn[i]=qpow(g,(p-1)/(1LL<<i));
	}
	void ntt(vector<int> &a,int len,int f)
	{
		int i,j=0,t,k,w,id;
		for(i=1;i<len-1;i++)
		{
			for(t=len;j^=t>>=1,~j&t;);
			if(i<j) swap(a[i],a[j]);
		}
		for(i=1,id=1;i<len;i<<=1,id++)
		{
			t=i<<1;
			for(j=0;j<len;j+=t)
			{
				for(k=0,w=1;k<i;k++,w=1ll*w*wn[id]%p)
				{
					int x=a[j+k],y=1ll*w*a[j+k+i]%p;
					a[j+k]=x+y;
					if(a[j+k]>=p) a[j+k]-=p;
					a[j+k+i]=x-y;
					if(a[j+k+i]<0) a[j+k+i]+=p;
				}
			}
		}
		if(f)
		{
			for(i=1,j=len-1;i<j;i++,j--) swap(a[i],a[j]);
			int inv=qpow(len,p-2);
			for(i=0;i<len;i++) a[i]=1ll*a[i]*inv%p;
		}
	}
	vector<int> mul(vector<int> &a,vector<int> &b)
	{
		int len,i,l1,l2;
		l1=a.size();
		l2=b.size();
		for(len=1;len<l1+l2;len<<=1);
		a.resize(len,0);
		b.resize(len,0);
		ntt(a,len,0);ntt(b,len,0);
		vector<int> res(len);
		for(i=0;i<len;i++) res[i]=1ll*a[i]*b[i]%p;
		ntt(res,len,1);
		res.resize(l1+l2-1);
		return res;
	}
};//NTT::getwn();
int s[MAX];
int main()
{
	NTT::getwn();
	int n,i;
	ll ans;
	scanf("%d",&n);
	vector<int> a(1e6+1,0),b(1e6+1,0);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		a[s[i]]++;
		b[s[i]]++;
	}
	vector<int> res=NTT::mul(a,b);
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(2*s[i]<res.size()) ans+=(res[2*s[i]]-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}
