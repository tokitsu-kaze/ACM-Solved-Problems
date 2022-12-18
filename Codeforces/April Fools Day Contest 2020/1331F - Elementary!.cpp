#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
	//inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend){
			p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template<class T> inline bool read(T &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
		return true;
	}
	inline bool read(double &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(ch=='.'){
			double tmp=1; ch=nc();
			for(;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
		}
		if(sign)x=-x;
		return true;
	}
	inline bool read(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
		*s=0;
		return true;
	}
	inline bool read(char &c){
		for(c=nc();blank(c);c=nc());
		if(IOerror){c=-1;return false;}
		return true; 
	}
	template<class T,class... U>bool read(T& h,U&... t){return read(h)&&read(t...);}
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
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
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
/************* define end  *************/
void read(int *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(ll *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(double *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
/*
void go()
{
	string s;
	vector<string > res;
	while(cin>>s)
	{
		if(s[0]>='A'&&s[0]<='Z') res.pb(s);
	}
	int cnt=0;
	for(auto it:res)
	{
		for(auto &c:it)
		{
			if(c>='a'&&c<='z') c=c-'a'+'A';
		}
		cnt++;
		printf("mp[\"%s\"]=1;",it.c_str());
		if(cnt%10==0) puts("");
	}
} 
*/

void go()
{
	map<string,int> mp;
	mp["H"]=1;mp["HE"]=1;mp["LI"]=1;mp["BE"]=1;mp["B"]=1;mp["C"]=1;mp["N"]=1;mp["O"]=1;mp["F"]=1;mp["NE"]=1;
	mp["NA"]=1;mp["MG"]=1;mp["AL"]=1;mp["SI"]=1;mp["P"]=1;mp["S"]=1;mp["CL"]=1;mp["AR"]=1;mp["K"]=1;mp["CA"]=1;
	mp["SC"]=1;mp["TI"]=1;mp["V"]=1;mp["CR"]=1;mp["MN"]=1;mp["FE"]=1;mp["CO"]=1;mp["NI"]=1;mp["CU"]=1;mp["ZN"]=1;
	mp["GA"]=1;mp["GE"]=1;mp["AS"]=1;mp["SE"]=1;mp["BR"]=1;mp["KR"]=1;mp["RB"]=1;mp["SR"]=1;mp["Y"]=1;mp["ZR"]=1;
	mp["NB"]=1;mp["MO"]=1;mp["TC"]=1;mp["RU"]=1;mp["RH"]=1;mp["PD"]=1;mp["AG"]=1;mp["CD"]=1;mp["IN"]=1;mp["SN"]=1;
	mp["SB"]=1;mp["TE"]=1;mp["I"]=1;mp["XE"]=1;mp["CS"]=1;mp["BA"]=1;mp["HF"]=1;mp["TA"]=1;mp["W"]=1;mp["RE"]=1;
	mp["OS"]=1;mp["IR"]=1;mp["PT"]=1;mp["AU"]=1;mp["HG"]=1;mp["TL"]=1;mp["PB"]=1;mp["BI"]=1;mp["PO"]=1;mp["AT"]=1;
	mp["RN"]=1;mp["FR"]=1;mp["RA"]=1;mp["RF"]=1;mp["DB"]=1;mp["SG"]=1;mp["BH"]=1;mp["HS"]=1;mp["MT"]=1;mp["DS"]=1;
	mp["RG"]=1;mp["CN"]=1;mp["NH"]=1;mp["FL"]=1;mp["MC"]=1;mp["LV"]=1;mp["TS"]=1;mp["OG"]=1;mp["LA"]=1;mp["CE"]=1;
	mp["PR"]=1;mp["ND"]=1;mp["PM"]=1;mp["SM"]=1;mp["EU"]=1;mp["GD"]=1;mp["TB"]=1;mp["DY"]=1;mp["HO"]=1;mp["ER"]=1;
	mp["TM"]=1;mp["YB"]=1;mp["LU"]=1;mp["AC"]=1;mp["TH"]=1;mp["PA"]=1;mp["U"]=1;mp["NP"]=1;mp["PU"]=1;mp["AM"]=1;
	mp["CM"]=1;mp["BK"]=1;mp["CF"]=1;mp["ES"]=1;mp["FM"]=1;mp["MD"]=1;mp["NO"]=1;mp["LR"]=1;
	string s,tmp;
	int ok,i;
	while(cin>>s)
	{
		ok=1;
		tmp="";
		for(i=sz(s)-1;~i;i--)
		{
			if(sz(tmp))
			{
				if(sz(tmp)>=2) break;
				tmp+=s[i];
				reverse(all(tmp));
				if(mp.count(tmp)) tmp="";
				else break;
			}
			else
			{
				if(mp.count(to_string(s[i]))) continue;
				else
				{
					tmp+=s[i];
					if(i+1<sz(s)) tmp+=s[i+1];
					if(mp.count(tmp)) tmp="";
					else tmp=to_string(s[i]);
				}
			}
		}
		if(tmp!="") ok=0;
		puts(ok?"YES":"NO");
	}
}

