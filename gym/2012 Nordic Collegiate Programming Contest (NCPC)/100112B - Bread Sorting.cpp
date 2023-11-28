#include <bits/stdc++.h>
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
	int i;
	ll ans;
	while(~scanf("%d",&n))
	{
		mem(bit,0);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++) pos[b[i]]=i;
		ans=0;
		for(i=1;i<=n;i++)
		{
			update(pos[a[i]],1);
			ans+=a[i]-getsum(pos[a[i]]);
		}
	//	cout<<ans<<endl;
		ans&1?puts("Impossible"):puts("Possible");
	}
	return 0;
}