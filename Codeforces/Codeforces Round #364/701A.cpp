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
const int MAX=3e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,a[111],s,now;
	while(~scanf("%d",&n))
	{
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		s/=(n/2);
		for(i=0;i<n;i++)
		{
			if(a[i]==-1) continue;
			now=a[i];
			a[i]=-1;
			for(j=0;j<n;j++)
			{
				if(a[j]==-1) continue;
				if(now+a[j]==s)
				{
					printf("%d %d\n",i+1,j+1);
					a[j]=-1;
					break;
				}
			}
		}
	}
	return 0;
}