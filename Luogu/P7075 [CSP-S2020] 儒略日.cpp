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
	inline bool read_line(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;ch!='\n'&&!IOerror;ch=nc())*s++=ch;
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
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll bc=4713*365+(4713-1)/4;
int ck(ll y)
{
	if(y<=1582) return y%4==0;
	if(y%400==0) return 1;
	if(y%4==0&&y%100!=0) return 1;
	return 0;
}
ll cal_y(ll y)
{
	if(y<=1582) return (y-1)*365+(y-1)/4;
	ll res=(y-1)*365+(y-1)/4-10;
	res-=((y-1)/100-1582/100);
	res+=((y-1)/400-1582/400);
	return res;
}
ll cal_bc_y(ll y)
{
	return (y-1)*365+(4713-1)/4-(4713-y)/4;
}
void go()
{
//	freopen("1.out","w",stdout);
	int q,i,tmp;
	ll x,l,r,mid,y,m,d;
//	debug(bc)
	while(read(q))
	{
		while(q--)
		{
			read(x);
			if(x<=bc)
			{
				x++;
				l=1;
				r=4713;
				while(l<r)
				{
					mid=(l+r)>>1;
					if(cal_bc_y(mid+1)<x) l=mid+1;
					else r=mid;
				}
				y=4713-l+1;
				x-=cal_bc_y(l);
		//		debug(y,cal_bc_y(l))
				for(m=1;m<=12;m++)
				{
					tmp=day[m];
					if(m==2&&y%4==1) tmp++;
		//			debug(m,tmp)
					if(tmp<x) x-=tmp;
					else break;
				}
				d=x;
				printf("%lld %lld %lld BC\n",d,m,y);
			}
			else
			{
				x-=bc;
				l=1;
				r=1e9;
				while(l<r)
				{
					mid=(l+r)>>1;
					if(cal_y(mid+1)<x) l=mid+1;
					else r=mid;
				}
				y=l;
				x-=cal_y(y);
				for(m=1;m<=12;m++)
				{
					tmp=day[m];
					if(m==2&&ck(y)) tmp++;
					if(y==1582&&m==10) tmp-=10;
					if(tmp<x) x-=tmp;
					else break;
				}
				d=x;
				if(y==1582&&m==10&&d>=5)
				{
					d+=10;
					assert(d<=day[10]);
				}
				printf("%lld %lld %lld\n",d,m,y);
			} 
		}
	}
}
/*
11
10
100
1000
2000000
3000000
4000000
283727928
1903988
1721423
1721422
1721424

31 7 772108
1 11 500
*/
