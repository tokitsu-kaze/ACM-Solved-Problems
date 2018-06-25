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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[222];
int main()
{
	int n,i,j,ans,pos;
	while(~scanf("%d",&n))
	{
		n*=2;
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=n;i;i-=2)
		{
			for(j=i-1;j;j--)
			{
				if(a[i]==a[j])
				{
					pos=j;
					break;
				}
			}
			for(j=pos;j<i-1;j++)
			{
				swap(a[j],a[j+1]);
				ans++;
			}
		}
	//	for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		printf("%d\n",ans);
	}
	return 0;
}

