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
typedef vector<PLL> VPLL;
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
//		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2000+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int hideres[MAX];
int x,cnt;
int ask(int p)
{
	int d;
	cout<<"? "<<p<<endl;
	cnt++;
	string s;
	cin>>s;
/*	if(hideres[p]>x) s+=">";
	else if(hideres[p]<x) s+="<";
	else s+="=";
	cout<<s<<endl;*/
	if(s[0]=='>') d=1;
	else if(s[0]=='<') d=-1;
	else if(s[0]=='=') d=0;
	else exit(0);
	x+=d;
//	debug(x)
	return d;
}
int ans[MAX];
void dfs(int l,int r,VI pos)
{
//	debug(l,r,sz(pos),pos)
	if(l==r)
	{
		if(sz(pos)==0) exit(0);
		ans[pos[0]]=l;
		return;
	}
	int prex,res;
	int mid=(l+r)>>1;
	VI lpos,rpos;
	while(sz(pos))
	{
		VI tmp;
//		debug(pos)
		for(auto it:pos)
		{
			prex=x;
			res=ask(it);
			if(prex<mid)
			{
				if(res==-1) lpos.pb(it);
				else tmp.pb(it);
			}
			else if(prex>mid)
			{
				if(res==1) rpos.pb(it);
				else tmp.pb(it);
			}
			else if(prex==mid)
			{
				if(res<=0) lpos.pb(it);
				else rpos.pb(it);
			}
		}
		while(x<mid&&sz(rpos)) ask(rpos[0]);
		while(x>mid&&sz(lpos)) ask(lpos[0]);
		pos=tmp;
	}
//	debug(lpos)
//	debug(rpos)
	dfs(l,mid,lpos);
	dfs(mid+1,r,rpos);
}
void go()
{
	int t,n,i,res,pre,p;
	cin>>t;
	while(t--)
	{
	/*	cin>>n>>x;
		for(i=1;i<=n;i++) cin>>hideres[i];*/
		cin>>n;
		if(n==1)
		{
			cout<<"! 1"<<endl;
			continue;
		}
		cnt=0;
		VI pos;
		for(i=1;i<=n;i++) pos.pb(i);
		p=-1;
		while(p==-1)
		{
			for(i=1;i<=n;i++)
			{
				res=ask(i);
				if(res!=0)
				{
					p=i;
					pre=res;
					break;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			while(1)
			{
				res=ask(i);
				if(res!=pre)
				{
					if(res!=0) ask(p);
					break;
				}
				else p=i;
			}
		}
		if(pre==1) x=n;
		else x=1;
		dfs(1,n,pos);
	//	debug(cnt)
		cout<<"!";
		for(i=1;i<=n;i++) cout<<" "<<ans[i];
		cout<<endl;
	}
}
