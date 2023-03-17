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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Point
{
	int flag;
	double x,y;
	Point(){}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}
};
typedef Point Vector;
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);} 
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
Point x[MAX];
void go()
{
	int n,i,pos[2],now[2];
	double ans,tmp[2];
	Point p[2],cen;
	while(read(p[0].x,p[0].y))
	{
		vector<pair<double,PII> > res;
		read(p[1].x,p[1].y);
		read(cen.x,cen.y);
		read(n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			read(x[i].x,x[i].y);
			res.pb(MP(dist(p[0],x[i])-dist(cen,x[i]),MP(i,0)));
			res.pb(MP(dist(p[1],x[i])-dist(cen,x[i]),MP(i,1)));
			ans+=2*dist(cen,x[i]);
		}
		sort(all(res));
		mem(now,0);
		vector<pair<double,int> > r[2];
		for(auto it:res)
		{
	//		debug(it.se.fi,it.se.se)
			r[it.se.se].pb(MP(it.fi,it.se.fi));
		}
		tmp[0]=r[0][0].fi;
		now[0]=r[0][0].se;
		r[1].pb(MP(0,-1000000000));
		sort(all(r[1]));
		for(i=0;i<sz(r[1]);i++)
		{
			if(r[1][i].se!=now[0])
			{
				tmp[0]+=r[1][i].fi;
				break;
			}
		}
		tmp[1]=r[1][0].fi;
		now[1]=r[1][0].se;
		if(now[1]<0)
		{
			tmp[1]=r[1][1].fi;
			now[1]=r[1][1].se;
		}
		r[0].pb(MP(0,-100000000));
		sort(all(r[0]));
		for(i=0;i<sz(r[0]);i++)
		{
			if(r[0][i].se!=now[1])
			{
				tmp[1]+=r[0][i].fi;
				break;
			}
		}
		printf("%.10f\n",ans+min(tmp[0],tmp[1]));
	}
}
/*
3 1000000000 1 2000000000 0 0
3
1 1
2 1
2 3

*/