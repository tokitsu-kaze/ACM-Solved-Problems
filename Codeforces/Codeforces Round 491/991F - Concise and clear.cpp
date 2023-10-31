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
const int MAX=2e5+10;
const ll mod=1e9+7;
/***************************************  head  **********************************************/

map<ll,string> mp;
set<ll> s[11];
ll n;
string to_str(ll x)
{
	string res="";
	while(x)
	{
		res+=x%10+'0';
		x/=10;
	}
	reverse(all(res));
	if(res=="") res+="0";
	return res;
}
string get(ll x)
{
	return mp.count(x)?mp[x]:to_str(x);
}
void add(ll x,string t)
{
	if(x>n||to_str(x).length()<=t.length()) return;
	if(mp.count(x)&&mp[x].length()<=t.length()) return;
	if(mp.count(x)) s[mp[x].length()].erase(x);
	s[t.length()].insert(x);
	mp[x]=t;
}
void work1()
{
	ll i,j,sq,p,q;
	sq=sqrt(n)+1;
	for(i=2;i<=sq;i++)
	{
		p=i;
		q=1;
		while(p<=n)
		{
			p=p*i;
			q++;
			add(p,to_str(i)+"^"+to_str(q));
		}
	}
}
void work2()
{
	ll i,j;
	for(i=1;i<=7;i++)
	{
		for(j=i;i+j+1<=7;j++)
		{
			for(auto it1:s[i])
			{
				for(auto it2:s[j])
				{
					add(it1*it2,mp[it1]+"*"+mp[it2]);
				}
			}
		}
	}
} 
void work3()
{
	ll i,j,tmp[12];
	tmp[0]=1;
	for(i=1;i<=10;i++) tmp[i]=tmp[i-1]*10;
	for(i=1;i+2<=7;i++)
	{
		for(j=2;j<tmp[7-i-1];j++)
		{
			for(auto it:s[i])
			{
				if(j*it>n) break;
				add(j*it,get(j)+"*"+mp[it]);
			}
		}
	}
}
string ans;
void up(string x)
{
	if(x.length()<ans.length()) ans=x;
}
void gao()
{
	ll i,j,tmp[12];
	tmp[0]=1;
	for(i=1;i<=10;i++) tmp[i]=tmp[i-1]*10;
	for(i=1;i*2+1<ans.length();i++)
	{
		for(j=1;j<=tmp[i];j++)
		{
			up(get(j)+"+"+get(n-j));
			if(n%j==0) up(get(n/j)+"*"+get(j));
		}
		for(auto it:s[i])
		{
			up(mp[it]+"+"+get(n-it));
			if(n%it==0) up(get(n/it)+"*"+mp[it]);
		}
	}
}
int main()
{
	int i;
	while(~scanf("%lld",&n))
	{
		for(i=0;i<=10;i++) s[i].clear();
		mp.clear();
		work1();
		work2();
		work3();
		ans=get(n);
		gao();
		cout<<ans<<"\n";
	}
	return 0;
}
