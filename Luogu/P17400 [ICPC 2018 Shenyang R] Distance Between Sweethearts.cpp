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
namespace FWT
{
	void fwt(ll *a,int n,int f,int v)
	{  
		for(int d=1;d<n;d<<=1)
		{
			for(int m=d<<1,i=0;i<n;i+=m)
			{
				for(int j=0;j<d;j++)
				{  
					ll x=a[i+j],y=a[i+j+d];
					if(!v)
					{
						if(f==1) a[i+j]=(x+y),a[i+j+d]=(x-y);
					}
					else
					{
						if(f==1) a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
					}
				}
			}
		}
	}
	void XOR(ll *res,ll *a,ll *b,ll *c,int n)
	{
		int len;
		for(len=1;len<n;len<<=1);
		fwt(a,len,1,0);
		fwt(b,len,1,0);
		fwt(c,len,1,0);
		for(int i=0;i<len;i++) res[i]=a[i]*b[i]*c[i];
		fwt(res,len,1,1);
	}
};
ll cnt[3][2222],pre[2222],tmp[3][2222],res[2222];
void go()
{
	int t,cas=1;
	ll I[2],A[2],G[2],i,j,mx;
	ull ans;
	read(t);
	while(t--)
	{
		read(I[0],A[0],G[0],I[1],A[1],G[1]);
		mem(cnt,0);
		mem(pre,0);
		ans=0;
		for(mx=0;mx<=2000;mx++)
		{
			for(i=0;i<=I[0]&&i+mx<=I[1];i++) cnt[0][i^(i+mx)]++;
			for(i=0;i<=A[0]&&i+mx<=A[1];i++) cnt[1][i^(i+mx)]++;
			for(i=0;i<=G[0]&&i+mx<=G[1];i++) cnt[2][i^(i+mx)]++;
			if(mx)
			{
				for(i=0;i<=I[1]&&i+mx<=I[0];i++) cnt[0][i^(i+mx)]++;
				for(i=0;i<=A[1]&&i+mx<=A[0];i++) cnt[1][i^(i+mx)]++;
				for(i=0;i<=G[1]&&i+mx<=G[0];i++) cnt[2][i^(i+mx)]++;
			}
			for(i=0;i<3;i++)
			{
				for(j=0;j<2048;j++)
				{
					tmp[i][j]=cnt[i][j];
				}
			}
			FWT::XOR(res,tmp[0],tmp[1],tmp[2],2048);
			for(i=0;i<2048;i++)
			{
				ans+=(res[i]-pre[i])*(i^mx);
				pre[i]=res[i];
			}
		}
		printf("Case #%d: %llu\n",cas++,ans);
	}
}