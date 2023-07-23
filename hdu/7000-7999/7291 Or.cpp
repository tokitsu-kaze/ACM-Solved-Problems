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
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct Segment_Tree
{
	#define type int
	static const int LOGN=32;
	int root,tot,ls[MAX*LOGN],rs[MAX*LOGN],ql,qr,n;
	type v[MAX*LOGN],qv;
	int newnode()
	{
		ls[tot]=rs[tot]=0;
		v[tot]=INF;
		return tot++;
	}
	void build(int _n)
	{
		n=_n;
		tot=0;
		root=newnode();
	}
	void pushup(int id)
	{
		v[id]=min(v[ls[id]],v[rs[id]]);
	}
	void update(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			v[id]=min(v[id],qv);
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
			res=min(res,v[id]);
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
		update(0,n,root);
	}
	type ask(int l,int r)//init res
	{
		ql=max(0,l);
		qr=r;
		if(ql>qr) return INF;
		res=INF;
		query(0,n,root);
		return res;
	}
	#undef type
}tr[2],tr2;
struct node{int r,id;};
int a[MAX],b[MAX],bit[MAX],nex[32][MAX];
const int MAXQ=1e6+10;
int ans[MAXQ];
vector<node> qst[MAX];
const int base=233;
void go()
{
	int t,n,q,l,r,i,f,p,s,mn[32];
	ll res,bs;
	read(t);
	while(t--)
	{
		read(n,q);
		read(a,1,n);
		read(b,1,n);
		bit[0]=0;
		for(i=1;i<=n;i++) bit[i]=bit[i-1]+b[i];
		for(s=0;s<30;s++)
		{
			tr[0].build(1<<s);
			tr[1].build(1<<s);
			tr2.build(1<<(s+1));
			for(i=n;i;i--)
			{
	//			p=bit[i]%(1<<s);
				p=bit[i]&((1<<s)-1);
				tr[(bit[i]>>s)&1].upd(p,p,i);
	//			p=bit[i]%(1<<(s+1));
				p=bit[i]&((1<<(s+1))-1);
				tr2.upd(p,p,i);
				if(bit[i]-a[i]>=0)
				{
					// bitr-(bitl-ai)
					f=((bit[i]-a[i])>>s)&1;
	//				p=(bit[i]-a[i])%(1<<s);
					p=(bit[i]-a[i])&((1<<s)-1);
					nex[s][i]=min(tr[f].ask(0,p-1),
								  tr[f^1].ask(p,1<<s));
				}
				else
				{
					// bitr+(ai-bitl)
	//				p=(a[i]-bit[i])%(1<<(s+1));
					p=(a[i]-bit[i])&((1<<(s+1))-1);
					nex[s][i]=min(tr2.ask((1<<s)-p,(1<<(s+1))-p-1),
								  tr2.ask((1<<s)+(1<<(s+1))-p,1<<(s+1)));
				}
			}
		}
		
		for(i=1;i<=n;i++) qst[i].clear();
		for(i=0;i<q;i++)
		{
			read(l,r);
			qst[l].pb({r,i});
		}
		mem(mn,0x3f);
		for(i=n;i;i--)
		{
			for(s=0;s<30;s++) mn[s]=min(mn[s],nex[s][i]);
			for(auto &it:qst[i])
			{
				ans[it.id]=0;
				for(s=0;s<30;s++)
				{
					if(mn[s]<=it.r) ans[it.id]|=(1<<s);
				}
			}
		}
		res=0;
		bs=1;
		for(i=0;i<q;i++)
		{
			bs=bs*base%mod;
			res=(res+1LL*ans[i]*bs)%mod;
		}
		printf("%lld\n",res);
	}
}

