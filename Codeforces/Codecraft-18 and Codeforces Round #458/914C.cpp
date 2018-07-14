#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e3+10;
const ll mod=1e9+7;
int res[1111];
void work()
{
	int i,now,t,k;
	mem(res,0);
	for(i=2;i<=1000;i++)
	{
		now=i;
		t=0;
		k=0;
		while(1)
		{
			k++;
			while(now)
			{
				if(now&1) t++;
				now>>=1;
			}
			if(res[t]||t==1)
			{
				res[i]=res[t]+k;
				break;
			}
			else
			{
				now=t;
				t=0;
			}
		}
	//	cout<<i<<" "<<res[i]<<endl;
	}
}
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x)
{
	return pow2(x,mod-2);
}
ll fac[MAX];
void init()
{
	ll i;
	fac[0]=1;
	for(i=1;i<MAX;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
}
ll C(ll n,ll m)
{
	if(m>n||m<0) return 0;
	return fac[n]*inv(fac[m]*fac[n-m]%mod)%mod;
} 
int main()
{
	work();
	init();
	char s[1111];
	int k,i,len,pos,c;
	ll ans;
	while(~scanf("%s%d",s,&k))
	{
		len=strlen(s);
		if(k==0)
		{
			puts("1");
			continue;
		}
		ans=0;
		pos=0;
		c=0;
		while(pos<len)
		{
			while(s[pos]=='1'&&pos<len) pos++,c++;
			pos++;
			for(i=0;i<=len-pos;i++)
			{
				if(res[i+c+1]==k-1)
				{
					ans-=C(len-pos,i);
					ans+=mod;
					ans%=mod;
				}
			}
		}
		for(i=1;i<=len;i++)
		{
			if(res[i]==k-1)
			{
				ans+=C(len,i);
				if(k==1) ans=ans-1+mod;
				ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
110
2
111111011
2
*/