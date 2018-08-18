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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
namespace kd_tree
{
	const double alpha=0.75;
	const int dim=2;
	#define type ll
	struct kdtnode
	{
		type x[dim],mx[dim],mn[dim],v,tag;
		int l,r,sz;
		kdtnode(){}
		void initval()
		{
			sz=1;tag=v;
			for(int i=0;i<dim;i++) mn[i]=mx[i]=x[i];
		}
		void init(type val){l=r=0;v=val;initval();}
		void set(int a,int b,type d=0){x[0]=a,x[1]=b;init(d);}
		kdtnode(int a,int b,type d=0){set(a,b,d);}
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
				t[0].mx[i]=-LLINF;
				t[0].mn[i]=LLINF;
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
		inline type dist(type x,type y){return x*x+y*y;}
		inline type dist(kdtnode x,kdtnode y){return dist(x.x[0]-y.x[0],x.x[1]-y.x[1]);}
		inline type getdist(int id)
		{
			if(!id) return LLINF;
			type res=0;
			if(q.x[0]<t[id].mn[0]) res+=dist(t[id].mn[0]-q.x[0],0);
			if(q.x[1]<t[id].mn[1]) res+=dist(t[id].mn[1]-q.x[1],0);
			if(q.x[0]>t[id].mx[0]) res+=dist(t[id].mx[0]-q.x[0],0);
			if(q.x[1]>t[id].mx[1]) res+=dist(t[id].mx[1]-q.x[1],0);
			return res;
		}
		int ng;
		ll now,pos;
		void query(int id)
		{
			if(!id) return;
			type res=dist(t[id],q);
			if(!res||id==ng) res=LLINF;
			if(res<now)
			{
				now=res;
				pos=id;
			}
			type dl,dr,l,r;
			dl=getdist(ls);
			dr=getdist(rs);
			l=ls;
			r=rs;
			if(dl>dr)
			{
				swap(dl,dr);
				swap(l,r);
			}
			if(dl<now) query(l);
			if(dr<now) query(r);
		}
		inline PLL query(kdtnode _q,int id){now=LLINF;ng=id;q=_q;query(root);return MP(now,pos);}
	}kd;
	#undef type
	#undef ls
	#undef rs
}
using namespace kd_tree;
void go()
{
	int t,n,i;
	ll ans;
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++) read(kd.t[i].x[0],kd.t[i].x[1]);
		kd.init(n);
		ans=0;
		int pos[3];
		auto gao=[&](int ng)->ll
		{
			ll res=LLINF;
			for(i=1;i<=n;i++)
			{
				if(i==ng) continue;
				PLL tmp=kd.query(kd.t[i],ng);
				if(tmp.fi<res)
				{
					res=tmp.fi;
					if(ng) continue;
					pos[0]=i;
					pos[1]=tmp.se;
				}
			}
			return res;
		};
		ans+=gao(0)*(n-2);
		ans+=gao(pos[0]);
		ans+=gao(pos[1]);
		printf("%lld\n",ans);
	}
}
