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
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
struct node
{
	int l,r,tp;
	friend bool operator <(node a,node b)
	{
		if(a.tp!=b.tp) return a.tp<b.tp;
		if(a.tp==3)
		{
			if(a.l!=b.l) return a.l>b.l;
			return a.r<b.r;
		}
		if(a.tp==1)
		{
			if(a.r!=b.r) return a.r<b.r;
			return a.l>b.l;
		}
		return 0;
	}
};
char s[MAX];
int main()
{
	ll ans;
	int t,n,i,j,len,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		vector<node> res;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			len=strlen(s);
			node t;
			t.l=t.r=0;
			for(j=0;j<len;j++)
			{
				if(s[j]=='(') t.l++;
				else
				{
					if(t.l)
					{
						t.l--;
						ans++;
					}
					else t.r++;
				}
			}
			if(t.l>t.r) t.tp=1;
			else if(t.l==t.r) t.tp=2;
			else t.tp=3;
			res.pb(t);
		}
		sort(all(res));
		tmp=0;
		for(i=0;i<sz(res);i++)
		{
			ans+=min(tmp,res[i].r);
			tmp-=min(tmp,res[i].r);
			tmp+=res[i].l;
		}
		printf("%lld\n",ans*2);
	}
	return 0;
}
/*
100
3
(((
)))
)( 
*/
