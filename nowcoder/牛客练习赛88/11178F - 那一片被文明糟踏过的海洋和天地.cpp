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
const int MAX=5e4+10;
const ll mod=998244353;
/*********************************  head  *********************************/
void assert_lr(int x,int l,int r){assert(x>=l&&x<=r);}
struct AC_Automaton
{
	map<int,int> nex[MAX];
	bitset<20001> v[MAX];
	bitset<50001> qst[MAX];
	VI leaf[MAX],toplist;
	int fail[MAX],last[MAX];
	int root,tot;
	int newnode()
	{
		tot++;
		nex[tot].clear();
		v[tot].reset();
		qst[tot].reset();
		return tot;
	}
	void init()
	{
		toplist.clear();
		tot=0;
		root=newnode();
	}
	void insert(VI &s,int x)
	{
		int len,now,i;
		len=sz(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=s[i];
			if(!nex[now].count(t)) nex[now][t]=newnode();
			now=nex[now][t];
		}
		v[now][x]=1;
		leaf[x].pb(now);
	}
	void work()
	{
		int i,now;
		queue<int>q;
		for(auto it:nex[root])
		{
			fail[it.se]=root;
			q.push(it.se);
		}
		fail[root]=1;
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			toplist.pb(now);
			//suffix link
		/*	if(cnt[fail[now]]) last[now]=fail[now];
			else last[now]=last[fail[now]];*/
			
			v[now]|=v[fail[now]];
			
			for(auto it:nex[now])
			{
				int fail_now=fail[now];
				while(fail_now>1&&!nex[fail_now].count(it.fi)) fail_now=fail[fail_now];
				if(nex[fail_now].count(it.fi)) fail[it.se]=nex[fail_now][it.fi];
				else fail[it.se]=root;
				q.push(it.se);
			}
		}
	}
	bitset<20001> query(VI& s,int x)
	{
		int len,now,i;
		len=sz(s);
		now=root;
		bitset<20001> res;
		for(i=0;i<len;i++)
		{
			int t=s[i];
			while(now>1&&!nex[now].count(t)) now=fail[now];
			if(nex[now].count(t)) now=nex[now][t];
			else now=root;
			res|=v[now];
			qst[now][x]=1;
		}
		return res;
	}
	void toptrans()
	{
		for(int i=sz(toplist)-1;~i;i--)  qst[fail[toplist[i]]]|=qst[toplist[i]];
	}
}ac;
int cnt[MAX];
void go()
{
	int n,m,i,j,k,x;
	while(read(n))
	{
		ac.init();
		for(i=1;i<=n;i++)
		{
			ac.leaf[i].clear();
			for(j=1;j<=3;j++)
			{
				read(k);
				VI tmp;
				while(k--)
				{
					read(x);
					tmp.pb(x);
				}
				ac.insert(tmp,i);
			}
			cnt[i]=0;
		}
		ac.work();
		read(m);
		for(i=1;i<=m;i++)
		{
			bitset<20001> res;
			for(j=1;j<=4;j++)
			{
				read(k);
				VI tmp;
				while(k--)
				{
					read(x);
					tmp.pb(x);
				}
				res|=ac.query(tmp,i);
			}
			printf("%d\n",res.count());
		}
		ac.toptrans();
		for(i=1;i<=n;i++)
		{
			bitset<50001> res;
			for(auto leaf:ac.leaf[i]) res|=ac.qst[leaf];
			cnt[i]=res.count();
		}
		println(cnt,1,n);
	}
}
