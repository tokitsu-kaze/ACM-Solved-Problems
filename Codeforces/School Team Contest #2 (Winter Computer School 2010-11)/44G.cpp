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
	#define type int
	const type NONE=INF;   //初始值 
	struct kdtnode
	{
		bool exist;
		int l,r,sz,fa,dep,x[dim],mx[dim],mn[dim];
		type v,tag;
		kdtnode(){}
		void initval()
		{
			sz=exist;tag=v;
			if(exist) for(int i=0;i<dim;i++) mn[i]=mx[i]=x[i];
		}
		void null()
		{
			exist=sz=0;
			v=tag=NONE;
			for(int i=0;i<dim;i++)
			{
				mx[i]=-INF;
				mn[i]=INF;
			}
		}
		void newnode(int x0,int x1,type val=NONE)
		{
			x[0]=x0;
			x[1]=x1;
			l=r=fa=0;
			exist=1;
			v=val;
			initval();
		}
		kdtnode(int a,int b,type d=NONE){newnode(a,b,d);}
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
			t[id].sz+=t[ls].sz+t[rs].sz;
			t[id].tag=min({t[ls].tag,t[rs].tag,t[id].tag});
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
		bool isbad(int id){return t[id].sz*alpha+3<max(t[ls].sz,t[rs].sz);}
		int st[MAX],top;
		void build(int &id,int l,int r,int fa,int dep=0)
		{
			id=0;if(l>r) return;
			int m=(l+r)>>1; idx=dep;
			nth_element(st+l,st+m,st+r+1,[&](int x,int y){return t[x].x[idx]<t[y].x[idx];});
			id=st[m];
			build(ls,l,m-1,id,(dep+1)%dim);
			build(rs,m+1,r,id,(dep+1)%dim);
			pushup(id);
			t[id].dep=dep;
			t[id].fa=fa;
		}
		inline void init(int n=0)
		{
			root=0;
			t[0].null();
			for(int i=1;i<=n;i++) st[i]=i;
			if(n) build(root,1,n,0);
			tot=n;
		}
		void travel(int id)
		{
			if(!id) return;
			if(t[id].exist) st[++top]=id;
			travel(ls);
			travel(rs);
		}
		void rebuild(int &id,int dep)
		{
			top=0;travel(id);
			build(id,1,top,t[id].fa,dep);
		}
		void insert(int &id,int now,int fa,int dep=0)
		{
			if(!id)
			{
				id=now;
				t[id].dep=dep;
				t[id].fa=fa;
				return;
			}
			if(t[now].x[dep]<t[id].x[dep]) insert(ls,now,id,(dep+1)%dim);
			else insert(rs,now,id,(dep+1)%dim);
			pushup(id);
			if(isbad(id)) rebuild(id,t[id].dep);
			t[id].dep=dep;
			t[id].fa=fa;
		}
		inline void insert(kdtnode x){t[++tot]=x;insert(root,tot,0,0);}
		inline void del(int id)
		{
			if(!id) return;
			t[id].null();
			int x=id;
			while(x)
			{
				pushup(x);
				x=t[x].fa;
			}
			if(isbad(id))
			{
				x=t[id].fa;
				rebuild(root==id?root:(t[x].l==id?t[x].l:t[x].r),t[id].dep);
			}
		}
		kdtnode a,b;
		inline int check(kdtnode &x)//x在矩形(a,b)内 
		{
			int ok=1;
			for(int i=0;i<dim;i++)
			{
				ok&=(x.x[i]>=a.x[i]);
				ok&=(x.x[i]<=b.x[i]);
			}
			return ok;
		}
		inline int allin(kdtnode &x)//x的子树全在矩形(a,b)内 
		{
			int ok=1;
			for(int i=0;i<dim;i++)
			{
				ok&=(x.mn[i]>=a.x[i]);
				ok&=(x.mx[i]<=b.x[i]);
			}
			return ok;
		}
		inline int allout(kdtnode &x)//x的子树全不在矩形(a,b)内 
		{
			int ok=0;
			for(int i=0;i<dim;i++)
			{
				ok|=(x.mx[i]<a.x[i]);
				ok|=(x.mn[i]>b.x[i]);
			}
			return ok;
		}
		int res;
		void query(int id)
		{
			if(!id) return;
			if(allout(t[id])||t[id].sz==0) return;
			if(allin(t[id]))
			{
				res=min(res,t[id].tag);
				return;
			}
			if(check(t[id])&&t[id].exist) res=min(res,t[id].v);
			int l,r;
			l=ls;
			r=rs;
			if(t[l].tag>t[r].tag) swap(l,r);
			if(t[l].tag<res) query(l);
			if(t[r].tag<res) query(r);
		}
		inline int query(kdtnode _a,kdtnode _b)
		{
			a=_a;b=_b;
			res=INF;
			query(root);
			if(res!=INF) del(res);
			return res;
		}
	}kd;
	#undef type
	#undef ls
	#undef rs
}
using namespace kd_tree;
struct node
{
	int x1,y1,x2,y2,z;
	int id;
	void input(int _id){read(x1,x2,y1,y2,z);id=_id;}
	friend bool operator <(node a,node b)
	{
		return a.z<b.z;
	}
}a[MAX];
int ans[MAX];
void go()
{
	int n,m,i;
	while(read(n))
	{
		mem(ans,0);
		for(i=1;i<=n;i++) a[i].input(i);
		sort(a+1,a+1+n);
		read(m);
		for(i=1;i<=m;i++)
		{
			int x,y;
			read(x,y);
			kd.t[i].newnode(x,y,i);
		}
		kd.init(m);
		for(i=1;i<=n;i++)
		{
			kdtnode x,y;
			x.newnode(a[i].x1,a[i].y1,i+1);
			y.newnode(a[i].x2,a[i].y2,i+1);
			int tmp=kd.query(x,y);
			if(tmp!=INF) ans[tmp]=a[i].id;
		}
		for(i=1;i<=m;i++) printf("%d\n",ans[i]);
	} 
}