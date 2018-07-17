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
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e9+7;
int a[MAX];
bool flag[MAX];
int main()
{
	int n,i,maxx1,maxx2,p1,p2;
	while(~scanf("%d",&n))
	{
		p1=p2=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		mem(flag,0);
		maxx1=0;
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				int now=i;
				int cnt=0;
				while(!flag[now])
				{
					flag[now]=1;
					cnt++;
					now=a[now];
				}
				if(cnt>maxx1)
				{
					maxx1=cnt;
					p1=i;
				}
			}
		}
		mem(flag,0);
		maxx2=0;
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				int now=i;
				int cnt=0;
				while(!flag[now])
				{
					flag[now]=1;
					cnt++;
					now=a[now];
				}
				if(cnt>maxx2&&p1!=i)
				{
					maxx2=cnt;
					p2=i;
				}
			}
		}
		swap(a[p1],a[p2]);
		ll ans=0;
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				int now=i;
				int cnt=0;
				while(!flag[now])
				{
					flag[now]=1;
					cnt++;
					now=a[now];
				}
				ans+=(ll)cnt*cnt;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}