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
int pos[MAX],flag[MAX];
int a[MAX];
int main()
{
	int n,k,i,x,tot,ans;
	while(~scanf("%d%d",&n,&k))
	{
		mem(pos,0);
		for(i=0;i<k;i++)
		{
			scanf("%d",&x);
			pos[x]++;
		}
		mem(flag,0);
		tot=k;
		ans=0;
		for(i=0;i<k;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+k);
		for(i=0;i<k;i++)
		{
			int t=a[i]-1;
			if(!t) t=n;
			if(pos[t]&&!flag[t])
			{
				ans++;
				tot--;
				flag[t]=1;
				continue;
			}
			t=a[i]+1;
			if(t>n) t=1;
			if(pos[t]&&!flag[t])
			{
				ans++;
				tot--;
				flag[t]=1;
			}
		}
		ans+=tot*2;
		printf("%d\n",ans);
	}
	return 0;
}