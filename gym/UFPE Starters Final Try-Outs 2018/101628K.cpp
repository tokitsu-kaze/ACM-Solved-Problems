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
const int MAX=5e5+10;
const ll mod=1e9+7;
map<pair<int,ull>,set<int> > Hash;
map<ull,set<int> > mp;
set<int> ::iterator it;
const ull seed=1e9+7;
void insert(string s,int len,int pos)
{
	int i;
	ull now=0;
	for(i=0;i<len;i++)
	{
		now=now*seed+s[i];
		Hash[MP(i+1,now)].insert(pos);
//		cout<<s.substr(0,i+1)<<" "<<now<<endl;
	}
	mp[now].insert(pos);
}
void del(string s,int len,int pos)
{
	int i;
	ull now=0;
	for(i=0;i<len;i++)
	{
		now=now*seed+s[i];
		Hash[MP(i+1,now)].erase(pos);
	}
	mp[now].erase(pos);
}
void query2()
{
	int l,r,i;
	string tmp;
	scanf("%d%d",&l,&r);
	cin>>tmp;
	ull now=0;
	for(i=0;i<tmp.length();i++)
	{
		now=now*seed+tmp[i];
		it=mp[now].lower_bound(l);
		if(it!=mp[now].end()&&*it<=r)
		{
			puts("Y");
			return;
		}
	}
	puts("N");
}
void query3()
{
	int l,r,i;
	string tmp;
	scanf("%d%d",&l,&r);
	cin>>tmp;
	ull now=0;
	for(i=0;i<tmp.length();i++)
	{
		now=now*seed+tmp[i];
	}
	it=Hash[MP(tmp.length(),now)].lower_bound(l);
	if(it!=Hash[MP(tmp.length(),now)].end()&&*it<=r) puts("Y");
	else puts("N");
}
string s[MAX];
int main()
{
	int n,i,q,op,x;
	string tmp;
	while(~scanf("%d",&n))
	{
		Hash.clear();
		mp.clear();
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			insert(s[i],s[i].length(),i+1);
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d",&x);
				cin>>tmp;
				del(s[x-1],s[x-1].length(),x);
				insert(tmp,tmp.length(),x);
				s[x-1]=tmp;
			}
			else if(op==2) query2();
			else query3();
		}
	}
	return 0;
}