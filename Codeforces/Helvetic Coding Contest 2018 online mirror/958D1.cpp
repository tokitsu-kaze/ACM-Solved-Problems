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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
double v[MAX];
char s[MAX];
int main()
{
	int a,b,c,n,i;
	while(~scanf("%d",&n))
	{
		map<double,int> mp;
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			sscanf(s,"(%d+%d)/%d",&a,&b,&c);
	//		cout<<a<<" "<<b<<" "<<c<<endl;
			v[i]=(a+b)*1.0/c;
	//		cout<<v[i]<<endl;
			mp[v[i]]++;
		}
		for(i=1;i<=n;i++) printf("%d%c",mp[v[i]]," \n"[i==n]);
	}
	return 0;
}