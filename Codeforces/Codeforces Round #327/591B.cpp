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
const int MAX=2e5+10;
const ll mod=1e9+7;
vector<int> mp[26];
char s[MAX],ans[MAX];
int main()
{
	int n,q,i,j,len;
	char a[5],b[5];
	while(~scanf("%d%d",&n,&q))
	{
		scanf("%s",s);
		len=strlen(s);
		for(i=0;i<26;i++) mp[i].clear();
		for(i=0;i<len;i++)
		{
			mp[s[i]-'a'].pb(i);
		}
		while(q--)
		{
			scanf("%s%s",a,b);
			swap(mp[a[0]-'a'],mp[b[0]-'a']);
		}
		for(i=0;i<26;i++)
		{
			for(j=0;j<sz(mp[i]);j++)
			{
				ans[mp[i][j]]='a'+i;
			}
		}
		ans[len]='\0';
		puts(ans);
	}
	return 0;
}