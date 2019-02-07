#include <bits/stdc++.h>
using namespace std;
/************* debug begin *************/
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(const bool& b){return(b?"true":"false");}
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
template<class A,class B>string to_string(pair<A,B> p){return "("+to_string(p.first)+", "+to_string(p.second)+")";}
template<class A>string to_string(const vector<A> v){
	int f=1;string res="{";for(const auto x:v){if(!f)res+= ", ";f=0;res+=to_string(x);}res+="}";
	return res;
}
void debug_out(){puts("");}
template<class T,class... U>void debug_out(const T& h,const U&... t){cout<<" "<<to_string(h);debug_out(t...);}
#ifdef tokitsukaze 
#define debug(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
/*************  debug end  *************/
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
//		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
VI mp[MAX];
int a[MAX],b[MAX];
PII res[MAX];
void dfs(int x,int fa)
{
	res[x].fi=res[fa].fi+a[x];
	res[x].se=res[fa].se+b[x];
	for(auto to:mp[x])
	{
		assert(to!=fa);
		dfs(to,x);
	}
}
void go()
{
	int t,n,q,i,x;
	scanf("%d",&t);
	assert(t<=10);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		assert(n>=1&&n<=20000);
		assert(q>=1&&q<=20000);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			assert(a[i]>=0&&a[i]<=300);
			assert(b[i]>=0&&b[i]<=300);
		}
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			assert(x>=1&&x<i);
			mp[x].pb(i);
		}
		res[0].fi=res[0].se=0;
		dfs(1,0);
		while(q--)
		{
			scanf("%d",&x);
			printf("%d %d\n",res[x].fi,res[x].se);
		}
	}
}