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
const int MAX=2e3+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Point
{  
	double x,y;
	Point(){}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}
	void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);} 
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double length(Vector a){return sqrt(dot(a,a));}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;} 
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
struct Line
{  
	Point a,b;
	Vector v; 
	double ang;
	Line(){}
	void twopoint(Point _a,Point _b)
	{
		a=_a;
		b=_b;
		v=b-a;
		ang=atan2(v.y,v.x);
	}
};
double DisPointToLine(Point p,Point a,Point b)
{
	Vector v1,v2;
	v1=b-a;
	v2=p-a; 
	return fabs(cross(v1,v2))/length(v1);
}
struct node
{
	int id;
	double v;
	node(){}
	node(int a,double b) :id(a),v(b){}
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
vector<node> mp[MAX];
bool flag[MAX];
double dis[MAX];
int tot;
void dij(int s)
{
	int i;
	priority_queue<node> q;
	node t,to;
	for(i=0;i<=tot;i++) dis[i]=1e15;
	mem(flag,0);
	dis[s]=0;
	q.push(node(s,dis[s]));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id]) continue;
		flag[t.id]=1;
		for(i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			if(dis[to.id]>dis[t.id]+to.v)
			{
				dis[to.id]=dis[t.id]+to.v;
				q.push(node(to.id,dis[to.id]));
			}
		}
	}
}
Point p[1010];
double r[1010];
void go()
{
	int n,i,j;
	double a,b,c1,c2;
	while(~scanf("%d%lf%lf%lf%lf",&n,&a,&b,&c1,&c2))
	{
		for(i=1;i<=n;i++)
		{
			p[i].input();
			scanf("%lf",&r[i]);
		}
		Line l1,l2;
		l1.twopoint(Point(0,-c1/b),Point(1,-(c1+a)/b));
		l2.twopoint(Point(0,-c2/b),Point(1,-(c2+a)/b));
		tot=n+2;
		mp[1].pb(node(2,fabs(c1-c2)/sqrt(a*a+b*b)));
		for(i=1;i<=n;i++)
		{
			mp[1].pb(node(i+2,max(0.0,DisPointToLine(p[i],l1.a,l1.b)-r[i])));
			mp[i+2].pb(node(1,max(0.0,DisPointToLine(p[i],l1.a,l1.b)-r[i])));
			mp[2].pb(node(i+2,max(0.0,DisPointToLine(p[i],l2.a,l2.b)-r[i])));
			mp[i+2].pb(node(2,max(0.0,DisPointToLine(p[i],l2.a,l2.b)-r[i])));
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				mp[i+2].pb(node(j+2,max(0.0,dist(p[i],p[j])-r[i]-r[j])));
			}
		}
		dij(1);
		printf("%.10f\n",dis[2]);
		for(i=0;i<=tot;i++) mp[i].clear();
	}
}
