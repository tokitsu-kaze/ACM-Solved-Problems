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
void assert_lr(ll x,ll l,ll r) {assert(x>=l&&x<=r);};
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
const int MAX=4e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
string s[MAX];
char tmp[MAX];
int dir[8][2]={1,1,1,-1,-1,1,-1,-1,  1,0,0,1,-1,0,0,-1};
VPII mp[MAX];
int n,m;
int dis[MAX],pre[MAX];
int ck(int x,int y)
{
	int i,nx,ny;
	for(i=4;i<8;i++)
	{
		nx=x+dir[i][0];
		ny=y+dir[i][1];
		if(nx<0||nx>=n||ny<0||ny>=m) continue;
		if(s[nx][ny]=='#') return 0;
	}
	return 1;
}
void bfs()
{
	int i,x;
	for(i=0;i<=n*m;i++)
	{
		dis[i]=INF;
		pre[i]=-1;
	}
	queue<int> q;
	for(i=0;i<n;i++)
	{
		dis[i*m]=(s[i][0]!='#');
		q.push(i*m);
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto to:mp[x])
		{
			if(to.se+dis[x]<dis[to.fi])
			{
				dis[to.fi]=dis[x]+to.se;
				q.push(to.fi);
				pre[to.fi]=x;
			}
		}
	}
}
void go()
{
	int t,i,j,k,x,y;
	int ans;
	read(t);
	while(t--)
	{
		read(n,m);
		for(i=0;i<=n*m;i++) mp[i].clear();
		for(i=0;i<n;i++)
		{
			read(tmp);
			s[i]=string(tmp);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(ck(i,j)==0) continue;
				for(k=0;k<4;k++)
				{
					x=i+dir[k][0];
					y=j+dir[k][1];
					if(x<0||x>=n||y<0||y>=m) continue;
					if(ck(x,y)==0) continue;
					mp[i*m+j].pb(MP(x*m+y,s[x][y]!='#'));
				}
			}
		}
		bfs();
		ans=INF;
		for(i=0;i<n;i++) ans=min(ans,dis[i*m+m-1]);
		if(ans==INF) puts("NO");
		else
		{
			puts("YES");
			for(i=0;i<n;i++)
			{
				if(ans==dis[i*m+m-1])
				{
					x=i*m+m-1;
					break;
				}
			}
			while(x!=-1)
			{
				s[x/m][x%m]='#';
				x=pre[x];
			}
			for(i=0;i<n;i++) puts(s[i].c_str());
		}
	}
}

