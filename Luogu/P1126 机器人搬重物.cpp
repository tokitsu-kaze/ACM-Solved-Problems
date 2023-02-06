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
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
/************* define end  *************/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********* gp_hash_table end  **********/
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
const int MAX=3e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node
{
	int x,y,d;
};
int n,m,mp[55][55],sx,sy,tx,ty;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int dis[55][55][4];
int ck(int x,int y)
{
	if(x<1 || y<1 || x+1>n || y+1>m) return 0;
	if(mp[x][y] || mp[x+1][y] || mp[x][y+1] || mp[x+1][y+1]) return 0;
	return 1;
}
void bfs(int d)
{
	int i;
	node t,nex;
	mem(dis,0x3f);
	queue<node> q;
	q.push({sx,sy,d});
	dis[sx][sy][d]=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.x==tx && t.y==ty)
		{
			printf("%d\n",dis[t.x][t.y][t.d]);
			return;
		}
	//	debug(t.x,t.y,t.d,dis[t.x][t.y][t.d])
		for(i=1;i<=3;i++)
		{
			nex=t;
			nex.x+=i*dir[nex.d][0];
			nex.y+=i*dir[nex.d][1];
			if(!ck(nex.x,nex.y)) break;
			if(dis[t.x][t.y][t.d]+1 < dis[nex.x][nex.y][nex.d])
			{
				dis[nex.x][nex.y][nex.d]=dis[t.x][t.y][t.d]+1;
				q.push(nex);
			}
		}
		nex=t;
		nex.d=(nex.d-1+4)%4;
		if(dis[t.x][t.y][t.d]+1 < dis[nex.x][nex.y][nex.d])
		{
			dis[nex.x][nex.y][nex.d]=dis[t.x][t.y][t.d]+1;
			q.push(nex);
		}
		nex=t;
		nex.d=(nex.d+1)%4;
		if(dis[t.x][t.y][t.d]+1 < dis[nex.x][nex.y][nex.d])
		{
			dis[nex.x][nex.y][nex.d]=dis[t.x][t.y][t.d]+1;
			q.push(nex);
		}
	}
	puts("-1");
	
}
void go()
{
	int i,j,d;
	char ss[2];
	read(n,m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			read(mp[i][j]);
		}
	}
	read(sx,sy,tx,ty);
	read(ss);
	if(ss[0]=='E') d=0;
	else if(ss[0]=='S') d=1;
	else if(ss[0]=='W') d=2;
	else d=3;
	bfs(d);
}
