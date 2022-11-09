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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
char mp[1010][1010];
PII pos[1010][1010];
int flag[1010][1010],n;
string tmp="LURD";
string tmp2="RDLU";
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int ok;
void dfs(int x,int y)
{
	int nx,ny;
	int f=0;
	for(int i=0;i<4;i++)
	{
		nx=x+dir[i][0];
		ny=y+dir[i][1];
		if(nx<1||nx>n||ny<1||ny>n) continue;
		if(pos[x][y].fi!=pos[nx][ny].fi||pos[x][y].se!=pos[nx][ny].se) continue;
		if(flag[nx][ny]) continue;
		flag[nx][ny]=1;
		if(mp[nx][ny]!='-') ok=0;
		mp[nx][ny]=tmp[i];
		f=1;
		dfs(nx,ny);
	}
	if(!f)
	{
		if(mp[x][y]=='X'&&(pos[x][y].fi!=x||pos[x][y].se!=y)) ok=0;
	}
}
void go()
{
	int i,j,k,x,y,nx,ny,f;
	while(read(n))
	{
		ok=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				read(pos[i][j].fi,pos[i][j].se);
				mp[i][j]='-';
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(pos[i][j].fi==-1) continue;
				mp[pos[i][j].fi][pos[i][j].se]='X';
			}
		}
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(mp[i][j]=='X')
				{
					flag[i][j]=1;
					dfs(i,j);
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(flag[i][j]) continue;
				if(pos[i][j].fi==-1)
				{
					x=i;
					y=j;
					f=0;
					for(k=0;k<4;k++)
					{
						nx=x+dir[k][0];
						ny=y+dir[k][1];
						if(nx<1||nx>n||ny<1||ny>n) continue;
						if(pos[nx][ny].fi==-1)
						{
							flag[nx][ny]=flag[x][y]=1;
							mp[x][y]=tmp2[k];
							mp[nx][ny]=tmp[k];
							dfs(x,y);
							dfs(nx,ny);
							f=1;
							break;
						}
					}
					if(!f) ok=0;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(mp[i][j]=='-') ok=0;
			}
		}
		if(!ok)
		{
			puts("INVALID");
			continue;
		}
		puts("VALID");
		for(i=1;i<=n;i++)
		{
			mp[i][n+1]='\0';
			puts(mp[i]+1);
		}
	}
}

