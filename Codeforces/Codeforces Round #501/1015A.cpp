#include bitsstdc++.h
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	fread-read
	bool IOerror=0;
	inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
	inline char nc(){
		static char buf[BUF_SIZE],p1=buf+BUF_SIZE,pend=buf+BUF_SIZE;
		if(p1==pend){
			p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return p1++;
	}
	inline bool blank(char ch){return ch==' 'ch=='n'ch=='r'ch=='t';}
	templateclass T inline bool read(T &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch='0'&&ch='9';ch=nc())x=x10+ch-'0';
		if(sign)x=-x;
		return true;
	}
	inline bool read(double &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch='0'&&ch='9';ch=nc())x=x10+ch-'0';
		if(ch=='.'){
			double tmp=1; ch=nc();
			for(;ch='0'&&ch='9';ch=nc())tmp=10.0,x+=tmp(ch-'0');
		}
		if(sign)x=-x;
		return true;
	}
	inline bool read(char s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;!blank(ch)&&!IOerror;ch=nc())s++=ch;
		s=0;
		return true;
	}
	inline bool read(char &c){
		for(c=nc();blank(c);c=nc());
		if(IOerror){c=-1;return false;}
		return true; 
	}
	templateclass T,class... Ubool read(T& h,U&... t){return read(h)&&read(t...);}
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
 debug begin 
string to_string(string s){return ''+s+'';}
string to_string(const char s){return to_string((string)s);}
string to_string(const bool& b){return(btruefalse);}
templateclass Tstring to_string(T x){ostringstream sout;soutx;return sout.str();}
templateclass A,class Bstring to_string(pairA,B p){return (+to_string(p.first)+, +to_string(p.second)+);}
templateclass Astring to_string(const vectorA v){
    int f=1;string res={;for(const auto xv){if(!f)res+= , ;f=0;res+=to_string(x);}res+=};
    return res;
}
void debug_out(){puts();}
templateclass T,class... Uvoid debug_out(const T& h,const U&... t){cout to_string(h);debug_out(t...);}
#ifdef tokitsukaze 
#define debug(...) cout[#__VA_ARGS__],debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
  debug end  
#pragma comment(linker, STACK1024000000,1024000000)
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
typedef pairint,int PII;
typedef pairll,ll PLL;
typedef vectorint VI;
typedef vectorll VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen(TEST.txt,r,stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
  head  
void go()
{
	int n,m,i,l,r,flag[111];
	while(read(m,n))
	{
		mem(flag,0);
		while(m--)
		{
			read(l,r);
			flag[l]++;
			flag[r+1]--;
		}
		for(i=1;i=n;i++) flag[i]+=flag[i-1];
		VI res;
		for(i=1;i=n;i++) if(!flag[i]) res.pb(i);
		printf(%dn,sz(res));
		for(i=0;isz(res);i++) printf(%d%c,res[i], n[i==sz(res)-1]);
	}
}