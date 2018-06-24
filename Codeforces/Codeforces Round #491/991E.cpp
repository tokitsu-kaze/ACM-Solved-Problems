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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll C(ll n,ll m)
{
	ll res=1,i,j;
	m=min(m,n-m);
	for(i=n,j=m;j>=1;i--,j--) res*=i;
	for(i=m;i>=1;i--)
	{
		assert(res%i==0);
		res/=i;
	}
	return res;
}
ll gao(string s)
{
	ll res,i,j,len,cnt[15],now,tmp;
	mem(cnt,0);
	len=(ll)s.length();
	for(i=0;i<len;i++) cnt[s[i]-'0']++;
	res=0;
	for(i=1;i<10;i++)
	{
		if(!cnt[i]) continue;
		cnt[i]--;
		now=0;
		tmp=1;
		for(j=0;j<10;j++)
		{
			tmp*=C(len-1-now,cnt[j]);
//			cout<<i<<" "<<len-1-now<<" "<<j<<" "<<cnt[j]<<endl;
			now+=cnt[j];
		}
		cnt[i]++;
		res+=tmp;
	}
	return res;
}
ll cnt[15],ans;
void dfs(int i,string s)
{
	if(i==10)
	{
		ans+=gao(s);
//		cout<<s<<endl;
		return;
	}
	dfs(i+1,s);
	ll tmp=cnt[i];
	while(tmp--)
	{
		s+='0'+i;
		dfs(i+1,s);
	}
}
int main()
{
	string s;
	ll i;
	while(cin>>s)
	{
		ans=0;
		mem(cnt,0);
		for(i=0;i<s.length();i++) cnt[s[i]-'0']++;
		sort(all(s));
		s.resize(unique(all(s))-s.begin());
		for(i=0;i<s.length();i++) cnt[s[i]-'0']--;
		dfs(0,s);
		printf("%lld\n",ans);
	}
	return 0;
}
