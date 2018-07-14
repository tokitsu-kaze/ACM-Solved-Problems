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
int bit[MAX],a[MAX],maxx[MAX];
int main()
{
	int n,d,i,ans,now,flag,s;
	while(~scanf("%d%d",&n,&d))
	{
		bit[0]=0;
		flag=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			bit[i]=bit[i-1]+a[i];
			if(bit[i]>d) flag=1;
		}
		if(flag)
		{
			puts("-1");
			continue;
		}
		maxx[n]=bit[n];
		for(i=n-1;i>=1;i--)
		{
			maxx[i]=max(maxx[i+1],bit[i]);
		}
		s=ans=now=0;
		for(i=1;i<=n;i++)
		{
			now+=a[i];
			if(a[i]==0)
			{
				if(now<0)
				{
					now+=d-maxx[i]-s;
					s+=d-maxx[i]-s;
					now=max(now,0);
					ans++;
				}
			}
	//		cout<<now+bit[i]<<endl;
			if(now>d)
			{
				ans=-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}