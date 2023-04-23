#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const int MAX=1e6+10;
const ll mod=998244353;
/****************************************  head  ****************************************/
int main()
{
	int n,i,flag;
	string s;
	while(~scanf("%d",&n))
	{
		cin>>s;
		vector<string> a[2];
		string now;
		flag=0;
		for(i=0;i<sz(s);i++)
		{
			if(s[i]=='(')
			{
				flag=1;
				if(sz(now)) a[0].pb(now),now="";
			}
			else if(s[i]==')')
			{
				flag=0;
				if(sz(now)) a[1].pb(now),now="";
			}
			else if(s[i]=='_')
			{
				if(sz(now)) a[flag].pb(now),now="";
			}
			else now+=s[i];
		}
		if(sz(now)) a[flag].pb(now);
		int ans=0;
		for(auto it:a[0]) ans=max(ans,sz(it));
		printf("%d %d\n",ans,sz(a[1]));
	}
	return 0;
}