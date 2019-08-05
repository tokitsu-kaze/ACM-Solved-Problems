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
const double PI=3.1415926;
const double eps=1e-6;
const int MAX=3e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
ll res[MAX],tmp[MAX],a[MAX],bit[MAX],dq[MAX];
int flag[MAX],tot;
ll n,s,m,k;
void gao(int pos)
{
	int i,j,tag=pos+1,top=0,len;
	ll cnt;
	for(i=pos;flag[i]!=tag;i=(i+k)%n)
	{
		tmp[++top]=a[i];
		flag[i]=tag;
	}
	for(i=1;i<=top;i++) tmp[i+top]=tmp[i+top*2]=tmp[i];
	cnt=m/top;
	len=m%top;
	if(!len&&cnt)
	{
		len=top;
		cnt--;
	}
	if(cnt)
	{
		cnt--;
		len+=top;
	}
	top=top*3;
	res[++tot]=0;
	bit[0]=0;
	for(i=1;i<=top;i++) bit[i]=bit[i-1]+tmp[i];
	int l,r;
	l=r=0;
	for(i=j=top;i;i--)
	{
		while(~j&&i-j<=len)
		{
			while(r-l&&j&&bit[dq[r-1]]<bit[j]) r--;
			dq[r++]=j--;
		}
		while(r-l&&dq[l]>i) l++;
		res[tot]=max(res[tot],bit[dq[l]]-bit[dq[r-1]]);
	}
	if(bit[top/3]>=0) res[tot]+=bit[top/3]*cnt;
}
void go()
{
	int t,cas=1,i;
	read(t);
	while(t--)
	{
		read(n,s,m,k);
		for(i=0;i<n;i++) read(a[i]);
		mem(flag,0);
		tot=0;
		for(i=0;i<n;i++)
		{
			if(flag[i]) continue;
			gao(i);
		}
		ll ans=-LLINF;
		for(i=1;i<=tot;i++) ans=max(ans,res[i]);
		printf("Case #%d: %lld\n",cas++,max(0LL,s-ans));
	}
}
/*
2
5 100 12 1
-10 1 2 3 5
6 100 12 5
1 2 3 4 -5 6

ans:
88
73
*/
