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
int main()
{
	string s;
	int pos[333];
	mem(pos,0);
	pos['a']=pos['e']=pos['i']=pos['o']=pos['u']=1;
	while(cin>>s)
	{
		int flag=0;
		for(int i=0;i<len(s)-1;i++)
		{
			if(s[i]=='n') continue;
			if(pos[s[i]]) continue;
			if(pos[s[i+1]]);
			else flag=1;
		}
		if(!pos[s[len(s)-1]]&&s[len(s)-1]!='n') flag=1;
		flag?puts("NO"):puts("YES");
	}
	return 0;	
}