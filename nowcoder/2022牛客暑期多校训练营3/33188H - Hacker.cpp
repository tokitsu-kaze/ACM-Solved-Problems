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
void assert_lr(ll x,ll l,ll r) {assert(x>=l&&x<=r);};
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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],tag[MAX<<2],lmx[MAX<<2],rmx[MAX<<2],mx[MAX<<2],qv;
	void pushup(int id)
	{
		v[id]=v[ls]+v[rs];
		lmx[id]=max(lmx[ls],v[ls]+lmx[rs]);
		rmx[id]=max(rmx[rs],v[rs]+rmx[ls]);
		mx[id]=max({mx[ls],mx[rs],rmx[ls]+lmx[rs]});
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		v[id]=lmx[id]=rmx[id]=mx[id]=0;
		if(l==r)
		{
			v[id]=lmx[id]=rmx[id]=mx[id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
		debug(l,r,v[id],mx[id],lmx[id],rmx[id])
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			//do something
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res,pre;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res=max(res,mx[id]);
			res=max(res,pre+lmx[id]);
			pre=max(rmx[id],pre+v[id]);
			return;
		}
		pushdown(id);
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
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=-LLINF;
		pre=0;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
struct Suffix_Automaton
{
	static const int N=MAX<<1;
	static const int K=26;// char size: [0,25]
	int tot,last,nex[N][K],fa[N],len[N],cnt[N],maxlen;
	int newnode()
	{
		tot++;
		fa[tot]=len[tot]=cnt[tot]=0;
		mem(nex[tot],0);
		return tot;
	}
	void init()
	{
		fa[0]=len[0]=cnt[0]=0;
		mem(nex[0],0);
		tot=0;
		maxlen=0;
		last=newnode();
	}
	void add(int x)
	{
		int p,q,np,nq;
		p=last;
		np=last=newnode();
		len[np]=len[p]+1;
		maxlen=max(maxlen,len[np]);
		cnt[last]=1;
		while(p&&!nex[p][x])
		{
			nex[p][x]=np;
			p=fa[p];
		}
		if(p==0) fa[np]=1;
		else
		{
			q=nex[p][x];
			if(len[q]==len[p]+1) fa[np]=q;
			else
			{
				nq=newnode();
				memcpy(nex[nq],nex[q],sizeof(nex[q]));
				len[nq]=len[p]+1;
				maxlen=max(maxlen,len[nq]);
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				while(p&&nex[p][x]==q)
				{
					nex[p][x]=nq;
					p=fa[p];
				}
			}
		}
	}
	int sum[N],tp[N];
	void topsort()
	{
		int i;
		for(i=1;i<=maxlen;i++) sum[i]=0;
		for(i=1;i<=tot;i++) sum[len[i]]++;
		for(i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
		for(i=1;i<=tot;i++) tp[sum[len[i]]--]=i;
		for(i=tot;i;i--) cnt[fa[tp[i]]]+=cnt[tp[i]];
	}
	void build_tree(VI mp[])
	{
		for(int i=1;i<=tot;i++) mp[i].clear();
		for(int i=1;i<=tot;i++) mp[fa[i]].pb(i);
	}
	int pos[N],id[N];
	void init_pos(char *s,int n)//s[1..n]
	{
		int now=1;
		for(int i=1;i<=tot;i++) id[i]=-1;
		for(int i=1;i<=n;i++)
		{
			now=nex[now][s[i]-'a'];
			pos[i]=now;
			id[now]=i;
		}
	}
	int st[N][21];
	void init_ST()
	{
		int i,j,x;
		for(i=1;i<=tot;i++)
		{
			x=tp[i];
			st[x][0]=fa[x];
			for(j=1;j<20;j++)
			{
				st[x][j]=st[st[x][j-1]][j-1];
			}
		}
	}
	int get_substr(int l,int r)//init_pos  init_ST
	{
		int now,tmp,i;
		now=pos[r];
		for(i=19;~i;i--)
		{
			tmp=st[now][i];
			if(tmp&&len[tmp]>=r-l+1) now=tmp;
		}
		return now;
	}
}sam;// sam.init();

char s[MAX];
ll v[MAX];
void go()
{
	int n,m,k,i;
	ll ans;
	while(read(n,m,k))
	{
		read(s+1);
		sam.init();
		for(i=1;i<=n;i++) sam.add(s[i]-'a');
		read(tr.a,1,m);
		tr.build(m);
		while(k--)
		{
			read(s+1);
			ans=0;
			int id=1,l=0;
			for(i=1;i<=m;i++)
			{
				while(!sam.nex[id][s[i]-'a'] && id!=1)
				{
					id=sam.fa[id];
					l=sam.len[id];
				}
				if(sam.nex[id][s[i]-'a'])
				{
					id=sam.nex[id][s[i]-'a'];
					l++;
				}
				debug(s[i],i-l+1,i)
				if(l>0) ans=max(ans,tr.ask(i-l+1,i));
			}
			printf("%lld\n",ans);
		}
	}
}

