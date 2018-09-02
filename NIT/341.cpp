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
const int MAX=1e6+10;
const ll mod=1e9+7;
char s[MAX];
int main()
{
	int i,len,ans,now;
	while(~scanf("%s",s+1))
	{
		len=strlen(s+1);
		now=0;
		hash_map<int,int> mp;
		ans=0;
		mp[0]=0;
		for(i=1;i<=len;i++)
		{
			if(s[i]=='1') now++;
			else now-=2;
			if(mp.count(now)) ans=max(ans,i-mp[now]);
			else mp[now]=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}