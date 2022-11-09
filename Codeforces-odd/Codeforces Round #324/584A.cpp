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
const int MAX=1e3+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int main()
{
	int n,t,i;
	while(~scanf("%d%d",&n,&t))
	{
		string s="";
		if(t==10)
		{
			if(n==1)
			{
				puts("-1");
				continue;
			}
			n--;
			s+='1';
			while(n--) s+='0';
		}
		else
		{
			n--;
			s+='0'+t;
			while(n--) s+='0';
		}
		cout<<s<<"\n";
	}
	return 0;
}