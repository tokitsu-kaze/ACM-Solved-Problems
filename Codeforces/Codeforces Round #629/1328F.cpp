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
struct Segment_Tree
{
	#define type ll
	int root,tot,ls[MAX*30],rs[MAX*30],ql,qr,n;
	type v[MAX*30],qv;
	int newnode()
	{
		ls[tot]=rs[tot]=0;
		v[tot]=0;
		return tot++;
	}
	void init(int _n)
	{
		n=_n;
		tot=0;
		root=newnode();
	}
	void pushup(int id)
	{
		v[id]=v[ls[id]]+v[rs[id]];
	}
	void update(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			v[id]+=qv;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]);
		if(qr>mid) update(mid+1,r,rs[id]);
		pushup(id);
	}
	type res;
	void query(int l,int r,int &id)
	{
		if(!id) return;
		if(l>=ql&&r<=qr)
		{
			res+=v[id];
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls[id]);
		if(qr>mid) query(mid+1,r,rs[id]);
	}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,root);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		res=0;
		query(1,n,root);
		return res;
	}
	#undef type
}tr,tr2;
int a[MAX];
void go()
{
	int n,k,i;
	ll ans,now,tmp,hs;
	while(read(n,k))
	{
		read(a,1,n);
		sort(a+1,a+1+n);
		tr.init(1e9+2);
		tr2.init(1e9+2);
		map<int,int> mp;
		for(i=1;i<=n;i++)
		{
			a[i]++;
			tr.upd(a[i],a[i],a[i]);
			tr2.upd(a[i],a[i],1);
			mp[a[i]]++;
	//		debug(a[i])
		}
		ans=LLINF;
		for(auto it:mp)
		{
			tmp=k-it.se;
	//		debug(it)
			if(tmp<=0)
			{
				ans=0;
				break;
			}
			hs=tr2.ask(1,it.fi-1);
			now=hs*(it.fi-1)-tr.ask(1,it.fi-1);
			if(hs<tmp)
			{
				tmp-=hs;
				now+=hs;
				now+=tr.ask(it.fi+1,1e9+2)-tr2.ask(it.fi+1,1e9+2)*(it.fi+1);
				now+=tmp;
			}
			else now+=tmp;
			ans=min(ans,now);
	//		debug(now)
			
			tmp=k-it.se;
			hs=tr2.ask(it.fi+1,1e9+2);
			now=tr.ask(it.fi+1,1e9+2)-hs*(it.fi+1);
			if(hs<tmp)
			{
				tmp-=hs;
				now+=hs;
				now+=tr2.ask(1,it.fi-1)*(it.fi-1)-tr.ask(1,it.fi-1);
				now+=tmp;
			}
			else now+=tmp;
			ans=min(ans,now);
	//		debug(now)
		}
		printf("%lld\n",ans);
	}
}
	
