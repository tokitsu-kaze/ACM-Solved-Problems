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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,k,a[33],flag,tag;
	int res[]={31,28,31,30,31,30,31,31,30,31,30,31};
	while(~scanf("%d",&n))
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==29) flag++,a[i]--;
		}
		if(flag>1)
		{
			puts("No");
			continue;
		}
		tag=0;
		for(i=0;i<12;i++)
		{
			flag=0;
			for(j=0,k=i;j<n;j++,k++)
			{
				k%=12;
				if(a[j]!=res[k])
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				tag=1;
				break;
			}
		}
		if(tag) puts("Yes");
		else puts("No");
	}
	return 0;
}