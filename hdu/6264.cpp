////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-05 15:19:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6264
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1696KB
//////////////////System Comment End//////////////////
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int t,i,ans,now,cnt;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		ans=cnt=now=0;
		map<char,int> mp;
		for(i=0;i<s.length();i+=2)
		{
			mp[s[i]]++;
			now=max(now,mp[s[i]]);
			cnt++;
		}
		ans+=cnt-now;
		mp.clear();
		cnt=now=0;
		for(i=1;i<s.length();i+=2)
		{
			mp[s[i]]++;
			now=max(now,mp[s[i]]);
			cnt++;
		}
		ans+=cnt-now;
		mp.clear();
		now=0;
		for(i=0;i<s.length();i++)
		{
			mp[s[i]]++;
			now=max(now,mp[s[i]]);
		}
		ans=min(ans,(int)s.length()-now);
		printf("%d\n",ans);
	}
	return 0;
}