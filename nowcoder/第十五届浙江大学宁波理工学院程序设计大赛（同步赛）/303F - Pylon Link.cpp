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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int n,flag[511];
ll x[511],y[511];
VI mp[511];
ll sqr(ll x){return x*x;}
ll dist(ll a,ll b){return sqr(x[a]-x[b])+sqr(y[a]-y[b]);}
void bfs()
{
	int t,i;
	queue<int> q;
	q.push(1);
	flag[1]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(auto to:mp[t])
		{
			if(!flag[to])
			{
				q.push(to);
				flag[to]=1;
			}
		}
	}
}
bool check(ll R)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		flag[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(dist(i,j)<=4*sqr(R))
			{
				mp[i].pb(j);
				mp[j].pb(i);
			}
		}
	}
	bfs();
	for(i=1;i<=n;i++)
	{
		if(!flag[i]) return 0;
	}
	return 1;
}
void go()
{
	int t,i,j;
	ll l,r,mid;
	scanf("%d",&t);
	assert(t<=20);
	while(t--)
	{
		scanf("%d",&n);
		assert(n>=2&&n<=500);
		set<PLL > s;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&x[i],&y[i]);
			assert(x[i]>=-1000000000&&x[i]<=1000000000);
			assert(y[i]>=-1000000000&&y[i]<=1000000000);
			s.insert(MP(x[i],y[i]));
		}
		assert(sz(s)==n);
		l=1;
		r=1500000000;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
} 