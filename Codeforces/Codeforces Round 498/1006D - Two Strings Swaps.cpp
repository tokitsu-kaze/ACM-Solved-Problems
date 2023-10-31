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
char a[MAX],b[MAX];
int main()
{
	int n,i,ans;
	while(~scanf("%d",&n))
	{
		scanf("%s %s",a+1,b+1);
		ans=0;
		for(i=1;i<=n/2;i++)
		{
			set<char> s;
			s.insert(a[i]);
			s.insert(a[n-i+1]);
			s.insert(b[i]);
			s.insert(b[n-i+1]);
			if(sz(s)==4) ans+=2;
			else if(sz(s)==3)
			{
				if(a[i]==a[n-i+1]) ans+=2;
				else ans++;
			}
			else if(sz(s)==2)
			{
				if((a[i]==b[i]&&a[n-i+1]==b[n-i+1])||(a[i]==b[n-i+1]&&a[n-i+1]==b[i]));
				else if(a[i]==a[n-i+1]&&b[i]==b[n-i+1]);
				else ans++;
			}
		}
		if(n&1)
		{
			if(a[(n+1)/2]!=b[(n+1)/2]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}