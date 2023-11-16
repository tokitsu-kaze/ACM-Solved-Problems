#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	#define ll long long
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
	//fwrite->print
	struct Ostream_fwrite{
		char *buf,*p1,*pend;
		Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
//		void out(char ch){putchar(ch);}
		void out(char ch){if(p1==pend){fwrite(buf,1,BUF_SIZE,stdout);p1=buf;}*p1++=ch;}
		template<class T>void print(T x){
			static char s[33],*s1;s1=s;
			if(!x)*s1++='0';if(x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1);
		}
		void print(double x,int y){
			static ll mul[]=
			{1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,
			10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
			100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
			if(x<-1e-12)out('-'),x=-x;
			ll x2=(ll)floor(x);if(!y&&x-x2>=0.5)++x2;x-=x2;x*=mul[y];
			ll x3=(ll)floor(x);if(y&&x-x3>=0.5)++x3;print(x2);
			if(y>0){out('.');for(size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i);print(x3);}
		}
		void print(char *s){while(*s)out(*s++);}
		void print(const char *s){while(*s)out(*s++);}
		void flush(){if(p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
		~Ostream_fwrite(){flush();}
	}Ostream;
	template<class T>void print(T x){Ostream.print(x);}
	inline void print(char x){Ostream.out(x);}
	inline void print(char *s){Ostream.print(s);}
	inline void print(string s){Ostream.print(s.c_str());}
	inline void print(const char *s){Ostream.print(s);}
	inline void print(double x,int y){Ostream.print(x,y);}
	template<class T,class... U>void print(const T& h,const U&... t){print(h);print(t...);}
	void println(){print('\n');}
	template<class T,class... U>void println(const T& h,const U&... t){print(h);println(t...);}
	inline void flush(){Ostream.flush();}
	#undef ll
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
const int mod=1000000007;
struct light_speed_pow
{
	#define type int
	int n,sq;
	type res[MAX][2],val;
	void init(int _n,type _val)
	{
		n=_n;
		val=_val;
		sq=sqrt(n)+1;
		res[0][0]=res[0][1]=1;
		for(int i=1;i<=sq;i++) res[i][0]=1ll*res[i-1][0]*val%mod;
		for(int i=1;i<=sq;i++) res[i][1]=1ll*res[i-1][1]*res[sq][0]%mod;
	}
	type qpow(int exp)
	{
		if(exp<=sq) return res[exp][0];
		return 1ll*res[exp/sq][1]*res[exp-exp/sq*sq][0]%mod;
	}
	#undef type
}lsp;
int modres(int x){if(x>=mod) x-=mod;return x;}
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct poly{int c,exp;};
	struct node
	{
		int op,allflag;
		type sum,lmul,rmul,alladd,allmul,lnum,rnum;
		poly lp,rp;
		vector<poly> p;
		void init()
		{
			p.clear();
		}
	}t[MAX<<2];
	int n,ql,qr,qop,aop[MAX],optag[MAX<<2];
	type a[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		int i,j,k;
		node res;
		res.init();
		res.op=y.op;
		res.alladd=modres(x.alladd+y.alladd);
		res.allmul=1ll*x.allmul*y.allmul%mod;
		res.lnum=x.lnum;
		res.rnum=y.rnum;
		if(x.op==0) // +
		{
			res.sum=modres(x.sum+y.sum);
			res.lmul=x.lmul;
			res.rmul=y.rmul;
			res.allflag=0;
			res.lp=x.lp;
			res.rp=y.rp;
			
			i=j=k=0;
			res.p.resize(x.p.size()+y.p.size()+5);
			while(i<x.p.size()&&j<y.p.size())
			{
				if(x.p[i].exp<y.p[j].exp) res.p[k++]=x.p[i++];
				else if(y.p[j].exp<x.p[i].exp) res.p[k++]=y.p[j++];
				else
				{
					res.p[k]=x.p[i++];
					res.p[k].c+=y.p[j++].c;
					k++;
				}
			}
			while(i<x.p.size()) res.p[k++]=x.p[i++];
			while(j<y.p.size()) res.p[k++]=y.p[j++];
			res.p.resize(k);
		}
		else // *
		{
			res.sum=(1ll*x.sum+y.sum-x.rmul-y.lmul
				+1ll*x.rmul*y.lmul)%mod;
			if(res.sum<0) res.sum+=mod;
			if(x.allflag)
			{
				res.lmul=1ll*x.allmul*y.lmul%mod;
				res.lp={1,x.lp.exp+y.lp.exp};
			}
			else
			{
				res.lmul=x.lmul;
				res.lp=x.lp;
			}
			if(y.allflag)
			{
				res.rmul=1ll*x.rmul*y.allmul%mod;
				res.rp={1,x.rp.exp+y.rp.exp};
			}
			else
			{
				res.rmul=y.rmul;
				res.rp=y.rp;
			}
			res.allflag=(x.allflag&y.allflag);
			
			poly tmp;
			tmp.c=1;
			tmp.exp=x.rp.exp+y.lp.exp;
			
			for(i=0;i<x.p.size();i++)
			{
				if(x.p[i].exp==x.rp.exp) x.p[i].c--;
				if(x.p[i].exp==tmp.exp)
				{
					x.p[i].c+=tmp.c;
					tmp.exp=INF;
				}
			}
			for(j=0;j<y.p.size();j++)
			{
				if(y.p[j].exp==y.lp.exp) y.p[j].c--;
				if(y.p[j].exp==tmp.exp)
				{
					y.p[j].c+=tmp.c;
					tmp.exp=INF;
				}
			}
			
			i=j=k=0;
			res.p.resize(x.p.size()+y.p.size()+5);
			while(i<x.p.size()&&j<y.p.size())
			{
				if(x.p[i].c==0)
				{
					i++;
					continue;
				}
				if(y.p[j].c==0)
				{
					j++;
					continue;
				}
				if(tmp.exp<x.p[i].exp&&tmp.exp<y.p[j].exp)
				{
					res.p[k++]=tmp;
					tmp.exp=INF;
					continue;
				}
				if(x.p[i].exp<y.p[j].exp) res.p[k++]=x.p[i++];
				else if(y.p[j].exp<x.p[i].exp) res.p[k++]=y.p[j++];
				else
				{
					res.p[k]=x.p[i++];
					res.p[k].c+=y.p[j++].c;
					k++;
				}
			}
			while(i<x.p.size())
			{
				if(tmp.exp<x.p[i].exp)
				{
					res.p[k++]=tmp;
					tmp.exp=INF;
					continue;
				}
				res.p[k++]=x.p[i++];
			}
			while(j<y.p.size())
			{
				if(tmp.exp<y.p[j].exp)
				{
					res.p[k++]=tmp;
					tmp.exp=INF;
					continue;
				}
				res.p[k++]=y.p[j++];
			}
			if(tmp.exp!=INF) res.p[k++]=tmp;
			res.p.resize(k);
		}
		return res;
	}
	void maintain_op(int l,int r,int id,int op)
	{
		t[id].op=op;
		if(op==0) // +
		{
			t[id].allflag=0;
			t[id].sum=t[id].alladd;
			t[id].lmul=t[id].lnum;
			t[id].rmul=t[id].rnum;
			t[id].lp=t[id].rp={1,1};
			t[id].p.clear();
			t[id].p.push_back({r-l+1,1});
		}
		else // *
		{
			t[id].allflag=1;
			t[id].sum=t[id].allmul;
			t[id].lmul=t[id].rmul=t[id].allmul;
			t[id].lp=t[id].rp={1,r-l+1};
			t[id].p.clear();
			t[id].p.push_back({1,r-l+1});
		}
	}
	void maintain_val(int l,int r,int id,type val)
	{
		if(val!=lsp.val || r-l+1>lsp.n) lsp.init(r-l+1,val);
		t[id].sum=0;
		for(auto &it:t[id].p) t[id].sum=(t[id].sum+1ll*lsp.qpow(it.exp)*it.c)%mod;
		t[id].lmul=1ll*lsp.qpow(t[id].lp.exp)*t[id].lp.c%mod;
		t[id].rmul=1ll*lsp.qpow(t[id].rp.exp)*t[id].rp.c%mod;
		t[id].alladd=1ll*(r-l+1)*val%mod;
		t[id].allmul=lsp.qpow(r-l+1);
		t[id].lnum=t[id].rnum=val;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		int mid=(l+r)>>1;
		if(optag[id]!=-1)
		{
			maintain_op(l,mid,ls,optag[id]);
			maintain_op(mid+1,r,rs,optag[id]);
			optag[ls]=optag[rs]=optag[id];
			optag[id]=-1;
		}
		if(tag[id]!=-1)
		{
			maintain_val(l,mid,ls,tag[id]);
			maintain_val(mid+1,r,rs,tag[id]);
			tag[ls]=tag[rs]=tag[id];
			tag[id]=-1;
		}
	}
	void build(int l,int r,int id)
	{
		tag[id]=optag[id]=-1;
		t[id].init();
		if(l==r)
		{
			t[id].sum=t[id].lmul=t[id].rmul=a[l];
			t[id].alladd=t[id].allmul=a[l];
			t[id].lnum=t[id].rnum=a[l];
			t[id].op=aop[l];
			t[id].allflag=1;
			t[id].p.push_back({1,1});
			t[id].lp=t[id].rp={1,1};
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			if(qop==1)
			{
				tag[id]=qv;
				maintain_val(l,r,id,qv);
			}
			else
			{
				optag[id]=qv;
				maintain_op(l,r,id,qv);
			}
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v,int _op)
	{
		ql=l;
		qr=r;
		qv=v;
		qop=_op;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1).sum;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int main()
{
	int n,m,i,op,l,r;
	ll x;
	read(n,m);
	for(i=1;i<=n;i++)
	{
		read(x);
		tr.a[i]=x%mod;
	}
	for(i=1;i<n;i++) read(tr.aop[i]);
	tr.build(n);
	while(m--)
	{
		read(op,l,r);
		if(op==1||op==2)
		{
			read(x);
			tr.upd(l,r,x%mod,op);
		}
		else println(tr.ask(l,r));
	}
	return 0;
}
