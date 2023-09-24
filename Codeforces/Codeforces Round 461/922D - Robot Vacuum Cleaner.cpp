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
const int MAX=1e6+10;
const ll mod=1e9+7;
struct node
{
	string s;
	ll a,b,c;
	friend bool operator <(node a,node b)
	{
		return a.a*b.b>a.b*b.a;
	}
}t;
int main()
{
	ll a,b,c;
	int n,i,j;
	while(~scanf("%d",&n))
	{
		vector<node> res;
		for(i=0;i<n;i++)
		{
			t.a=t.b=t.c=0;
			cin>>t.s;
			for(j=0;j<t.s.length();j++)
			{
				if(t.s[j]=='s') t.a++;
				else
				{
					t.b++;
					t.c+=t.a;
				}
			}
			res.pb(t);
		}
		a=b=c=0;
		sort(all(res));
		for(i=0;i<sz(res);i++)
		{
			c+=res[i].c;
			c+=res[i].b*a;
			a+=res[i].a;
		}
		printf("%lld\n",c);
	}
	return 0;
}