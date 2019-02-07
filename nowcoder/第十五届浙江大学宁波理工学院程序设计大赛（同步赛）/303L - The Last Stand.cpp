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
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
ll pos[1011],v[1011],d[1011],dp[1011];
void go()
{
	int t,n,m,h,i,j;
	scanf("%d",&t);
	assert(t<=30);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&h);
		assert(n>=1&&n<=1000);
		assert(m>=1&&m<=int(1e9));
		assert(h>=1&&h<=int(1e9));
		pos[0]=v[0]=d[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&pos[i],&v[i],&d[i]);
			assert(pos[i]>pos[i-1]);
			assert(v[i]>=-int(1e9)&&v[i]<=int(1e9));
			assert(d[i]>=-int(1e9)&&d[i]<=int(1e9));
		}
		assert(m>pos[n]);
		pos[n+1]=m;
		v[n+1]=d[n+1]=0;
		n++;
		mem(dp,-0x3f);
		dp[0]=h;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(dp[j]+v[j]<=0||dp[j]+v[j]+d[j]*(pos[i]-pos[j])<=0) continue;
				dp[i]=max(dp[i],dp[j]+v[j]+d[j]*(pos[i]-pos[j]));
			}
		}
		printf("%lld\n",dp[n]);
	}
}