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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,a[1011],flag[1011],ans,now,tag;
	while(~scanf("%d",&n))
	{
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		mem(flag,0);
		sort(a+1,a+1+n);
		now=a[1];
		flag[1]=1;
		while(1)
		{	
			tag=0;
			for(i=1;i<=n;i++)
			{
				if(flag[i]) continue;
				if(a[i]>now)
				{
					now=a[i];
					flag[i]=1;
					tag=1;
					ans++;
					break;
				}
			}
			if(!tag)
			{
				for(i=1;i<=n;i++)
				{
					if(!flag[i])
					{
						now=a[i];
						tag=1;
						flag[i]=1;
						break;
					}
				}
			}
			if(!tag) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
5
1 2 2 2 3
*/