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
const double eps=1e-4;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int n,m,i,j,x,s1[222],s2[222];
	while(~scanf("%d%d",&n,&m))
	{
		mem(s1,0);
		mem(s2,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&x);
				s2[i]+=x;
				s1[j]+=x;
			}
		}
		printf("%d",s2[0]);
		for(i=1;i<n;i++)
		{
			printf(" %d",s2[i]);
		}
		puts("");
		printf("%d",s1[0]);
		for(i=1;i<m;i++)
		{
			printf(" %d",s1[i]);
		}
		puts("");
	}
	return 0;
}