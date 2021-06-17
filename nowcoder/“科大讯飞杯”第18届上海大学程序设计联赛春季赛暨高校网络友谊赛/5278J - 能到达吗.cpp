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
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct dsu
{
	int pre[MAX*20];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	int qv,tag[MAX<<2];
	VI v[MAX<<2],tag2[MAX<<2];
	void pushdown(int id)
	{
		if(!tag[id]) return;
		if(tag[id]&1)
		{
			tag[ls]|=1;
			tag[rs]|=1;
			v[ls].clear();
			v[rs].clear();
			tag2[ls].clear();
			tag2[rs].clear();
		}
		if(tag[id]&2)
		{
			tag[ls]|=2;
			tag[rs]|=2;
			for(auto it:tag2[id])
			{
				v[ls].pb(it);
				v[rs].pb(it);
				tag2[ls].pb(it);
				tag2[rs].pb(it);
			}
			tag2[id].clear();
		}
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		v[id].clear();
		tag2[id].clear();
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void update(int l,int r,int id)
	{
		v[id].pb(qv);
		if(l>=ql&&r<=qr)
		{
			tag2[id].pb(qv);
			tag[id]|=2;
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
	}
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			for(auto it:v[id]) dsu.merge(it,qv);
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void clear()
	{
		v[1].clear();
		tag2[1].clear();
		tag[1]=1;
	}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	void ask(int l,int r,int v)
	{
	//	debug(l,r,v)
		ql=l;
		qr=r;
		qv=v;
		query(1,n,1);
	}
	#undef type
	#undef ls
	#undef rs
}tr;
VI mp[MAX];
int flag[MAX],tot;
vector<pair<int,PII> > now;
int v[MAX*20],res[MAX*20];
int add(int l,int r,int co=1)
{
	int val=r-l+1;
	if(val<=0) return 0;
	tot++;
	v[tot]=val;
	if(co!=1) v[tot]=1ll*v[tot]*co%mod;
	now.pb(MP(tot,MP(l,r)));
	return 1;
}
const int inv2=(mod+1)/2;
int cal(int x)
{
	int res=1ll*x*(x-1)%mod*inv2%mod;
	res+=x;
	if(res>=mod) res-=mod;
	return res;
}
void go()
{
	int t,n,m,i,k,a,b,pre,l,r;
	int ans;
	read(t);
	tr.build(2e5);
	for(i=1;i<=MAX-10;i++)
	{
		mp[i].clear();
		flag[i]=0;
	}
	while(t--)
	{
		read(n,m);
		read(k);
		if(k==0)
		{
			printf("%d\n",cal(1ll*n*m%mod));
			continue;
		}
		tr.n=m;
		dsu.init(3*k+5);
		for(i=1;i<=3*k+5;i++) v[i]=res[i]=0;
		VI tmp;
		for(i=1;i<=k;i++)
		{
			read(a,b);
			mp[a].pb(b);
			if(!flag[a])
			{
				flag[a]=1;
				tmp.pb(a);
			}
		}
		if(!flag[1])
		{
			tmp.pb(1);
			mp[1].pb(0);
			mp[1].pb(m+1);
			flag[1]=1;
		}
		if(!flag[n])
		{
			tmp.pb(n);
			mp[n].pb(0);
			mp[n].pb(m+1);
			flag[n]=1;
		}
		sort(all(tmp));
		tot=0;
		tr.clear();
		pre=0;
		for(auto it:tmp)
		{
			sort(all(mp[it]));
			now.clear();
			if(pre!=it-1)
			{
				add(1,m,(it-1)-(pre+1)+1);
				tr.ask(1,m,tot);
				tr.clear();
				for(auto x:now) tr.upd(x.se.fi,x.se.se,x.fi);
				now.clear();
			}
			for(i=1;i<sz(mp[it]);i++)
			{
				l=mp[it][i-1]+1;
				r=mp[it][i]-1;
				if(add(l,r)&&it!=1) tr.ask(l,r,tot);
			}
			if(add(1,mp[it][0]-1)&&it!=1) tr.ask(1,mp[it][0]-1,tot);
			if(add(mp[it].back()+1,m)&&it!=1) tr.ask(mp[it].back()+1,m,tot);
			tr.clear();
			for(auto x:now) tr.upd(x.se.fi,x.se.se,x.fi);
			pre=it;
	//		debug(now)
		}
		assert(tot<=3*k+5);
		for(i=1;i<=tot;i++)
		{
			a=dsu.find(i);
			res[a]+=v[i];
			if(res[a]>=mod) res[a]-=mod;
		}
		ans=0;
		for(i=1;i<=tot;i++)
		{
			if(!res[i]) continue;
	//		debug(res[i])
			ans=(ans+cal(res[i]));
			if(ans>=mod) ans-=mod;
		}
		printf("%d\n",ans);
		for(auto it:tmp)
		{
			mp[it].clear();
			flag[it]=0;
		}
	}
}

