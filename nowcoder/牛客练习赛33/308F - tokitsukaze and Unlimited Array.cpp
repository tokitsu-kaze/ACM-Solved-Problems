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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
ll tmp[]={1,682498929,491101308,76479948,723816384,67347853,27368307,
625544428,199888908,888050723,927880474,281863274,661224977,623534362,
970055531,261384175,195888993,66404266,547665832,109838563,933245637,
724691727,368925948,268838846,136026497,112390913,135498044,217544623,
419363534,500780548,668123525,128487469,30977140,522049725,309058615,
386027524,189239124,148528617,940567523,917084264,429277690,996164327,
358655417,568392357,780072518,462639908,275105629,909210595,99199382,
703397904,733333339,97830135,608823837,256141983,141827977,696628828,
637939935,811575797,848924691,131772368,724464507,272814771,326159309,
456152084,903466878,92255682,769795511,373745190,606241871,825871994,
957939114,435887178,852304035,663307737,375297772,217598709,624148346,
671734977,624500515,748510389,203191898,423951674,629786193,672850561,
814362881,823845496,116667533,256473217,627655552,245795606,586445753,
172114298,193781724,778983779,83868974,315103615,965785236,492741665,
377329025,847549272,698611116};
void go()
{
	int n,m,i,a,b,pos;
	ll ans;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			if(b==n) ans=a;
		}
		ans%=mod;
		pos=n/10000000;
		ans=ans*tmp[pos]%mod;
		for(i=pos*10000000+1;i<=n;i++) ans=ans*i%mod;
		printf("%lld\n",ans);
	}
}