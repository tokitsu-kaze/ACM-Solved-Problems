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
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int cnt[MAX],flag[MAX];
void go()
{
	int n,k,i,j,x,a,b;
	while(~scanf("%d%d",&n,&k))
	{
		mem(cnt,0);
		mem(flag,0);
		vector<int> v;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(!flag[x]) v.pb(x);
			flag[x]++;
		}
		for(i=0;i<sz(v);i++)
		{
			for(j=v[i];j<=k;j+=v[i])
			{
				cnt[j]+=flag[v[i]];
			}
		}
		a=b=0;
		for(i=1;i<=k;i++) a=max(a,cnt[i]);
		for(i=1;i<=k;i++)
		{
			if(cnt[i]==a) b++;
		}
		printf("%d %d\n",a,b);
	}
}