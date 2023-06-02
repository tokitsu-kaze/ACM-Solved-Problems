////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-11 23:33:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2613
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1732KB
//////////////////System Comment End//////////////////
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
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;
map<string,ll> mp;
map<string,ll> ::iterator it;
char s[MAX];
string name1,name2;
ll p,q;
ll lcm(ll x,ll y){return x/__gcd(x,y)*y;}
void update()
{
	ll g=0;
	for(it=mp.begin();it!=mp.end();it++)
	{
		if(!g) g=it->se;
		else g=__gcd(g,it->se);
	}
	if(g&&g!=1)
	{
		for(it=mp.begin();it!=mp.end();it++) it->se/=g;
	}
}
int main()
{
	ll n,len,i,j;
	while(~scanf("%lld",&n))
	{
		getchar();
		mp.clear();
		for(i=1;i<=n;i++)
		{
			name1.clear();
			name2.clear();
			gets(s);
	//		puts(s);
			len=strlen(s);
			for(j=0;s[j]!=' '||s[j+1]!='#';j++) name1+=s[j];
			j+=3;
			for(;j<=len-5;j++) name2+=s[j];
			p=s[len-3]-'0';
			q=s[len-1]-'0';
			if(!mp[name1]&&!mp[name2])
			{
				mp[name1]=p;
				mp[name2]=q;
				update();
				continue;
			}
			if(!mp[name1])
			{
				swap(name1,name2);
				swap(p,q);
			}
			ll p1=mp[name1];
			ll _lcm=lcm(p1,p);
			ll _temp_map=_lcm/p1;
			ll _temp_out=_lcm/p;
			for(it=mp.begin();it!=mp.end();it++) it->se*=_temp_map;
			q*=_temp_out;
			mp[name2]=q;
			update();
		}
		for(it=mp.begin();it!=mp.end();it++)
		{
			printf("%s %lld\n",it->fi.c_str(),it->se);
		}
		puts("");
	}
	return 0;
}
