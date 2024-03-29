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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int mp[11][11],n,m,tag[22];
ll dp[7][11][11][11][11][11][11];
#define DP(x) dp[x][mp[x][1]][mp[x][2]][mp[x][3]][mp[x][4]][mp[x][5]][mp[x][6]]
ll dfs(int x,int y,int mdf)
{
	if(x==n+1) return mdf;
	if(y==1&&x-1>=1&&DP(x-1)!=-1) return DP(x-1);
	if(mp[x][y]==-1)
	{
		ll res=0;
		for(int i=0;i<=9;i++)
		{
			if(x-1>=1&&!tag[mp[x-1][y]+i]) continue;
			if(y-1>=1&&!tag[mp[x][y-1]+i]) continue;
			if(x+1<=n&&mp[x+1][y]!=-1&&!tag[mp[x+1][y]+i]) continue;
			if(y+1<=m&&mp[x][y+1]!=-1&&!tag[mp[x][y+1]+i]) continue;
			mp[x][y]=i;
			if(y==m)
			{
				DP(x)=dfs(x+1,1,1);
				res+=DP(x);
			}
			else res+=dfs(x,y+1,1);
			mp[x][y]=-1;
		}
		return res;
	}
	else
	{
		if(y==m&&DP(x)!=-1) return DP(x);
		if(y==m) return DP(x)=dfs(x+1,1,mdf);
		else return dfs(x,y+1,mdf);
	}
}
void go()
{
	int i,j;
	char s[11];
	mem(tag,0);
	tag[2]=tag[3]=tag[5]=tag[7]=tag[11]=tag[13]=tag[17]=tag[19]=1;
	while(read(n,m))
	{
		mem(dp,-1);
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			read(s+1);
			for(j=1;j<=m;j++)
			{
				if(s[j]>='0'&&s[j]<='9') mp[i][j]=s[j]-'0';
				else mp[i][j]=-1;
			}
		}
		printf("%lld\n",dfs(1,1,0));
	}
}
