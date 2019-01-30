#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//	inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************head*********************************/
const ll loop=86400;
int sec[86500],tot,day[150000],ds,cur;
int s,m,h,d,dt,mt;
ll perioid,dd,ss,x,ans;
int md[][12] ={
	{31,28,31,30,31,30,31,31,30,31,30,31}, 
	{31,29,31,30,31,30,31,31,30,31,30,31}
};
int leap(int x){return ((x%400==0)||(x%100!=0))&&(x%4==0);}
int check(int _mt,int _dt,int _d)
{
	if(mt!=-1&&mt!=_mt) return 0;
	if((dt==-1&&d==-1)||dt==_dt||d==_d) return 1;
	return 0;
}
void init()
{
	int i,j,k;
	tot=0;
	for(i=0;i<24;i++)
	{
		if(!(h==-1||h==i)) continue;
		for(j=0;j<60;j++)
		{
			if(!(m==-1||m==j)) continue;
			for(k=0;k<60;k++)
			{
				if(!(s==-1||s==k)) continue;
				sec[tot++]=i*3600+j*60+k;
			}
		}
	}
	for(i=0;i<400;i++)
	{
		for(j=0;j<12;j++)
		{
			for(k=0;k<md[leap(i+1970)][j];k++)
			{
				if(check(j,k,(cur+3)%7)) day[ds++]=cur;
				cur++;
			}
		}
	}
	perioid=cur*loop;
}
void go()
{
	int q,id,pos;
	while(read(s,m,h,d,dt,mt))
	{
		if(d>0) d--;
		if(dt>0) dt--;
		if(mt>0) mt--;
		init();
		read(q);
		while(q--)
		{
			read(x);
			ans=x-x%perioid;
			x=x-ans;
			dd=x/loop;
			ss=x%loop;
			pos=lower_bound(day,day+ds,dd)-day;
			if(pos==ds) ans+=perioid+day[0]*loop+sec[0];
			else if(day[pos]>dd)ans+=day[pos]*loop+sec[0];
			else
			{
				id=upper_bound(sec,sec+tot,ss)-sec;
				if(id<tot) ans+=day[pos]*loop+sec[id];
				else
				{
					pos++;
					if(pos==ds)ans+=perioid+day[0]*loop+sec[0];
					else ans+=day[pos]*loop+sec[0];
				}
			}
			printf("%lld\n",ans);
		}
	}
}