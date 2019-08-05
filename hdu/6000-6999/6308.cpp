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
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int main()
{
	int t,h,m,sgn;
	char s[555];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d %s",&h,&m,s);
		sgn=(s[3]=='+'?1:-1);
		double tmp;
		sscanf(s+4,"%lf",&tmp);
		int t=(int)(tmp*10+0.1);
		h=h*60+m;
		h+=sgn*t*6-8*60;
		(h+=24*60)%=(24*60);
		printf("%02d:%02d\n",h/60,h%60);
	}
	return 0;
}
