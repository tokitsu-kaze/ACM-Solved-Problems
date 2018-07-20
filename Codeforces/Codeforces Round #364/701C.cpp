#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
char s[MAX];
int mp[333];
int main()
{
	int n,i,l,ans,sum;
	while(~scanf("%d%s",&n,s+1))
	{
		l=1;
		ans=INF;
		set<char> t;
		sum=0;
		for(i=1;i<=n;i++) t.insert(s[i]);
		sum=sz(t);
		t.clear();
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			mp[s[i]]++;
			t.insert(s[i]);
			while(mp[s[l]]>1&&l<i)
			{
				mp[s[l]]--;
				l++;
			}
			if(sz(t)==sum) ans=min(ans,i-l+1);
	//		cout<<l<<" "<<i<<endl;
		}
		if(n==1) puts("1");
		else printf("%d\n",ans);
	}
	return 0;
}