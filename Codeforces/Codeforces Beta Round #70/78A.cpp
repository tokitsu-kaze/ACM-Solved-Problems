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
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int main()
{
	char s[1111];
	int i,j,len,pos[333],now;
	mem(pos,0);
	pos['a']=pos['e']=pos['i']=pos['o']=pos['u']=1;
	while(~scanf(" %[^\n]",s))
	{
		len=strlen(s);
		VI res;
		now=0;
		for(i=0;i<len;i++) now+=pos[s[i]];
		res.pb(now);
		for(j=0;j<2;j++)
		{
			scanf(" %[^\n]",s);
			len=strlen(s);
			now=0;
			for(i=0;i<len;i++) now+=pos[s[i]];
			res.pb(now);
		}
		if(res[0]==5&&res[1]==7&&res[2]==5) puts("YES");
		else puts("NO");
	}
	return 0;
}