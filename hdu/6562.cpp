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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type v[MAX<<2],qv;
	type len[MAX<<2],tag_head[MAX<<2],tag_tail[MAX<<2],tag_len[MAX<<2];
	void pushup(int id)
	{
		len[id]=len[ls]+len[rs];
		if(len[id]>=mod) len[id]-=mod;
		v[id]=v[ls]+v[rs];
		if(v[id]>=mod) v[id]-=mod;
	}
	void build(int l,int r,int id)
	{
		tag_head[id]=tag_tail[id]=0;
		tag_len[id]=1;
		if(l==r)
		{
			len[id]=1;
			v[id]=0;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void pushdown(int l,int r,int id)
	{
		if(tag_len[id]==1) return;
		int mid=(l+r)>>1;
		len[ls]=len[ls]*tag_len[id]%mod;
		len[rs]=len[rs]*tag_len[id]%mod;
		v[ls]=(v[ls]*tag_len[id]+len[ls]*tag_head[id]+tag_tail[id]*(mid-l+1))%mod;
		v[rs]=(v[rs]*tag_len[id]+len[rs]*tag_head[id]+tag_tail[id]*(r-mid))%mod;
		len[ls]=len[ls]*tag_len[id]%mod;
		len[rs]=len[rs]*tag_len[id]%mod;
		tag_tail[ls]=(tag_tail[ls]*tag_len[id]+tag_tail[id])%mod;
		tag_tail[rs]=(tag_tail[rs]*tag_len[id]+tag_tail[id])%mod;
		tag_head[ls]=(tag_head[id]*tag_len[ls]+tag_head[ls])%mod;
		tag_head[rs]=(tag_head[id]*tag_len[rs]+tag_head[rs])%mod;
		tag_len[ls]=tag_len[ls]*tag_len[id]%mod;
		tag_len[rs]=tag_len[rs]*tag_len[id]%mod;
		tag_len[id]=1;
		tag_head[id]=tag_tail[id]=0;
	//	debug(tag_head[ls],tag_tail[ls])
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			v[id]=(v[id]*10+(len[id]*10+(r-l+1))*qv)%mod;
			len[id]=len[id]*100%mod;
			tag_head[id]=(tag_head[id]+qv*tag_len[id])%mod;
			tag_tail[id]=(tag_tail[id]*10+qv)%mod;
			tag_len[id]=tag_len[id]*10%mod;
	//		debug(id,tag_head[id],tag_tail[id],v[id],len[id])
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res+=v[id];
			if(res>=mod) res-=mod;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		res=0;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
void go()
{
	int t,n,q,i,l,r,v,cas=1;
	char op[22];
	read(t);
	while(t--)
	{
		read(n,q);
		tr.build(n);
		printf("Case %d:\n",cas++);
		while(q--)
		{
			read(op);
			read(l,r);
			if(op[0]=='w')
			{
				read(v);
				tr.upd(l,r,v);
			}
			else printf("%lld\n",tr.ask(l,r));
		}
	}
}
