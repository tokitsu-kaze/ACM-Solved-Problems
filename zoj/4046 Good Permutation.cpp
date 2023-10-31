#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int bit[MAX],n;
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int v)
{
	while(x<=n)
	{
		bit[x]+=v;
		x+=lowbit(x);
	}
}
int getsum(int x)
{
	int res=0;
	while(x)
	{
		res+=bit[x];
		x-=lowbit(x);
	}
	return res;
}
int a[MAX],b[MAX],pos[MAX];
int main()
{
	int t,i,j,k;
	ll ans,now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=i;
			bit[i]=0;
		}
	/*	for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				pos[(i+k-1)%n]=i;
				if((i+k-1)%n==0) pos[n]=i;
			}
			for(i=1;i<=n;i++)
			{
				b[i]=pos[a[i]];
				bit[i]=0;
				printf("%d%c",b[i]," \n"[i==n]);
			}
			ans=0;
			for(i=n;i>=1;i--)
			{
				ans+=getsum(b[i]);
				update(b[i],1);
			}
			cout<<ans<<endl;
		}
		puts("*********");*/
		
		for(i=1;i<=n;i++)
		{
			pos[(i+1-1)%n]=i;
			if((i+1-1)%n==0) pos[n]=i;
		}
		for(i=1;i<=n;i++)
		{
			b[i]=pos[a[i]];
			bit[i]=0;
		}
		now=0;
		for(i=n;i>=1;i--)
		{
			now+=getsum(b[i]);
			update(b[i],1);
		}
		for(i=1;i<=n;i++)
		{
			pos[b[i]]=i;
		}
		ans=now;
	//	cout<<now<<endl;
		for(i=2;i<=n;i++)
		{
			now+=n-pos[i-1]-pos[i-1]+1;
			ans=min(ans,now);
	/*		cout<<pos[i]<<" "<<pos[i-1]<<endl;
			cout<<now<<endl;*/
		}
		printf("%lld\n",ans);
	}
	return 0;
}

