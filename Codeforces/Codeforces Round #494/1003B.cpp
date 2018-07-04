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
const double eps=1e-4;
const int MAX=5e5+10;
const ll mod=998244353;
int main()
{
	int a,b,x,i,f;
	while(~scanf("%d%d%d",&a,&b,&x))
	{
		string ans="";
		if(a>b) ans+='0',a--,f=1;
		else ans+='1',b--,f=0;
		while(x>1)
		{
			x--;
			ans+=f+'0';
			if(f) b--;
			else a--;
			f^=1;
		}
		if(!f)
		{
			while(b--) ans+='1';
			while(a--) ans+='0';
		}
		else
		{
			while(a--) ans+='0';
			while(b--) ans+='1';
		}
		cout<<ans<<endl;
	}
	return 0;
} 
