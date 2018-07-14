#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int x[MAX];
int main()
{
	int n,i,a,b,flag;
	while(~scanf("%d",&n))
	{
		flag=0;
		scanf("%d%d",&a,&b);
		x[1]=max(a,b);
		for(i=2;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			if(max(a,b)<=x[i-1]) x[i]=max(a,b);
			else x[i]=min(a,b);
		}
		for(i=2;i<=n;i++)
		{
			if(x[i]>x[i-1]) flag=1;
		}
		flag==0?puts("YES"):puts("NO");
	}
	return 0;
}