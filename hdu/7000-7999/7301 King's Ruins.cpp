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
const int MAX=5e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
namespace kd_tree
{
	const double alpha=0.75;
	const int dim=5;
	#define type int
	struct kdtnode
	{
		type x[dim],mx[dim],mn[dim],v,sum;
		int l,r,sz;
		kdtnode(){}
		void initval()
		{
			sz=1;sum=v;
			for(int i=0;i<dim;i++) mn[i]=mx[i]=x[i];
		}
		void init(type val){l=r=0;v=val;initval();}
		kdtnode(vector<type> a,type d=0)
		{
			for(int i=0;i<dim;i++) x[i]=a[i];
			init(d);
		}
	};
	struct KDT
	{
		#define ls t[id].l
		#define rs t[id].r
		kdtnode t[MAX];
		int tot,idx,root;
		inline void pushup(int id)
		{
			t[id].initval();
			t[id].sz=t[ls].sz+t[rs].sz+1;
			if(ls) t[id].sum=max(t[id].sum,t[ls].sum);
			if(rs) t[id].sum=max(t[id].sum,t[rs].sum);
			for(int i=0;i<dim;i++)
			{
				if(ls)
				{
					t[id].mx[i]=max(t[id].mx[i],t[ls].mx[i]);
					t[id].mn[i]=min(t[id].mn[i],t[ls].mn[i]);
				}
				if(rs)
				{
					t[id].mx[i]=max(t[id].mx[i],t[rs].mx[i]);
					t[id].mn[i]=min(t[id].mn[i],t[rs].mn[i]);
				}
			}
		}
		int st[MAX],top;
		void build(int &id,int l,int r,int dep=0)
		{
			id=0;if(l>r) return;
			int m=(l+r)>>1; idx=dep;
			nth_element(st+l,st+m,st+r+1,[&](int x,int y){return t[x].x[idx]<t[y].x[idx];});
			id=st[m];
			build(ls,l,m-1,(dep+1)%dim);
			build(rs,m+1,r,(dep+1)%dim);
			pushup(id);
		}
		inline void init(int n=0)
		{
			root=0;
			t[0].sz=0;
			for(int i=0;i<dim;i++)
			{
				t[0].mx[i]=-INF;
				t[0].mn[i]=INF;
			}
			for(int i=1;i<=n;i++) st[i]=i;
			if(n) build(root,1,n);
			tot=n+1;
		}
		void travel(int id)
		{
			if(!id) return;
			st[++top]=id;
			travel(ls);
			travel(rs);
		}
		void rebuild(int &id,int dep)
		{
			top=0;travel(id);
			build(id,1,top,dep);
		}
		void insert(int &id,int now,int dep=0)
		{
			if(!id){id=now;return;}
			idx=dep;
			if(t[now].x[idx]<t[id].x[idx]) insert(ls,now,(dep+1)%dim);
			else insert(rs,now,(dep+1)%dim);
			pushup(id);
			if(t[id].sz*alpha+3<max(t[ls].sz,t[rs].sz)) rebuild(id,dep);
		}
		inline void insert(kdtnode &x){t[++tot]=x;insert(root,tot);}
		kdtnode q;
		inline int check(kdtnode &x)
		{
			int ok=1;
			for(int i=0;i<dim;i++) ok&=(x.x[i]<=q.x[i]);
			return ok;
		}
		inline int allin(kdtnode &x)
		{
			int ok=1;
			for(int i=0;i<dim;i++) ok&=(x.mx[i]<=q.x[i]);
			return ok;
		}
		inline int allout(kdtnode &x)
		{
			int ok=0;
			for(int i=0;i<dim;i++) ok|=(x.mn[i]>q.x[i]);
			return ok;
		}
		type query(int id)
		{
			if(!id) return 0;
			type res=0;
			if(allin(t[id])) return t[id].sum;
			if(allout(t[id])) return 0;
			if(check(t[id])) res=max(res,t[id].v);
			int l=ls,r=rs;
			if(t[l].sum<t[r].sum) swap(l,r);
			if(t[l].sum>res) res=max(res,query(l));
			if(t[r].sum>res) res=max(res,query(r));
			return res;
		}
		inline type query(kdtnode _q){q=_q;return query(root);}
	}kd;
	#undef type
	#undef ls
	#undef rs
}
using namespace kd_tree;
void go()
{
	int t,n,i,a,b,c,d,e,v;
	read(t);
	while(t--)
	{
		read(n);
		kd.init();
		kdtnode tmp;
		for(i=1;i<=n;i++)
		{
			read(a,b,c,d,e,v);
			tmp=kdtnode(VI{a,b,c,d,e},kd.query(kdtnode(VI{a,b,c,d,e}))+v);
			kd.insert(tmp);
			printf("%d\n",tmp.v);
		}
	}
}
