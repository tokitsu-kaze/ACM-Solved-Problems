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
const double eps=1e-6;
const int MAX=4e5+10;
const ll mod=998244353;
char s[MAX];
int flag[MAX];
int main()
{
	int i,n,k,now;
	while(~scanf("%d%d",&n,&k))
	{
		scanf("%s",s);
		VI res[33];
		mem(flag,0);
		for(i=0;i<26;i++) res[i].clear();
		for(i=0;i<n;i++)
		{
			res[s[i]-'a'].pb(i);
		}
		now=0;
		while(k>0)
		{
			for(i=0;i<sz(res[now]);i++)
			{
				if(k==0) break;
				flag[res[now][i]]++;
				k--;
			}
			now++;
		}
		string ans="";
		for(i=0;i<n;i++)
		{
			if(flag[i]) continue;
			ans+=s[i];
		}
		cout<<ans<<"\n";
 	}
	return 0;
}
