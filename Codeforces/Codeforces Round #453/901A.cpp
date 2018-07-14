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
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int h,i,j,flag,now;
	while(~scanf("%d",&h))
	{
		for(i=0;i<=h;i++)
		{
			scanf("%d",&a[i]);
		}
		flag=0;
		for(i=1;i<=h;i++)
		{
			if(a[i-1]>1&&a[i]>1)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			puts("perfect");
			continue;
		}
		puts("ambiguous");
		vector<int> ans;
		now=0;
		for(i=0;i<=h;i++)
		{
			for(j=0;j<a[i];j++)
			{
				if(i==0) ans.pb(0);
				else if(i==1) ans.pb(1);
				else ans.pb(now);
			}
			now+=a[i];
		}
		printf("%d",ans[0]);
		for(i=1;i<sz(ans);i++) printf(" %d",ans[i]);
		puts("");
		ans.clear();
		now=0;
		int pre=0;
		for(i=0;i<=h;i++)
		{
			for(j=0;j<a[i];j++)
			{
				if(i==0) ans.pb(0);
				else if(i==1) ans.pb(1);
				else
				{
					if(pre>1&&a[i]>1) ans.pb(now-1),pre=-1;
					else ans.pb(now);
				}
			}
			now+=a[i];
			if(pre!=-1) pre=a[i];
		}
		printf("%d",ans[0]);
		for(i=1;i<sz(ans);i++) printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}