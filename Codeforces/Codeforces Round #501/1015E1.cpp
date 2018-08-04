#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
	inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
/*	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend){
			p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return *p1++;
	}*/
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
	//	freopen("TEST.txt","r",stdin);
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
char mp[1111][1111];
int bitx[1111][1111],bity[1111][1111],flag[1111][1111],k;
struct node{int x,y,v;};
void go()
{
	int n,m,i,j,lx,rx,ly,ry,ans;
	while(read(n,m))
	{
		for(i=1;i<=n;i++) read(mp[i]+1);
		mem(bitx,0);
		mem(bity,0);
		for(i=1;i<=n;i++)
		{
			bitx[i][0]=0;
			for(j=1;j<=m;j++)
			{
				bitx[i][j]=bitx[i][j-1]+(mp[i][j]=='*');
				flag[i][j]=(mp[i][j]=='*');
			}
		}
		for(j=1;j<=m;j++)
		{
			bitx[j][0]=0;
			for(i=1;i<=n;i++)
			{
				bity[j][i]=bity[j][i-1]+(mp[i][j]=='*');
			}
		}
		vector<node> res;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]=='.') continue;
				ans=0;
		//		debug(i,j);
				for(k=1;k<=min(n,m);k++)
				{
					if(i-k<=0||i+k>n) break;
					if(j-k<=0||j+k>m) break;
					lx=i-k;
					rx=i+k;
					ly=j-k;
					ry=j+k;
		//			debug(i,ly,i,ry);
		//			debug(lx,j,rx,j);
					if(bitx[i][ry]-bitx[i][ly-1]!=bity[j][rx]-bity[j][lx-1]) break;
					if(bitx[i][ry]-bitx[i][ly-1]!=2*k+1) break;
					
					ans=k;
				}
				if(!ans) continue;
		//		debug(ans);
				res.pb({i,j,ans});
				flag[i][j]=0;
				for(k=1;k<=ans;k++)
				{
					lx=i-k;
					rx=i+k;
					ly=j-k;
					ry=j+k;
					debug(i,ly,i,ry);
					debug(lx,j,rx,j);
					flag[i][ly]=flag[i][ry]=flag[lx][j]=flag[rx][j]=0;
				}
			}
		}
		ans=sz(res);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(flag[i][j])
				{
					ans=-1;
					debug(i,j);
				}
			}
		}
		printf("%d\n",ans);
		if(ans==-1) continue;
		for(i=0;i<ans;i++) printf("%d %d %d\n",res[i].x,res[i].y,res[i].v);
	}
}