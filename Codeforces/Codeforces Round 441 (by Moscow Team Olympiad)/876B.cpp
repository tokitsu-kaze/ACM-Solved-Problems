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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> v[MAX];
int main()
{
	int n,k,m,i,j,x,flag;
	while(~scanf("%d%d%d",&n,&k,&m))
	{
		for(i=0;i<=m;i++)
		{
			v[i].clear();
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			v[x%m].pb(x);
		}
		flag=0;
		for(i=0;i<=m;i++)
		{
			if(sz(v[i])>=k)
			{
				flag=1;
				puts("Yes");
				sort(all(v[i]));
				printf("%d",v[i][0]);
				for(j=1;j<sz(v[i])&&j<k;j++)
				{
					printf(" %d",v[i][j]);
				}
				puts("");
				break;
			}
		}
		if(!flag) puts("No");
	}
	return 0;
}