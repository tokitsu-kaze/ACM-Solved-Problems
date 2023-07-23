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
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Splay
{
	#define type PII
	const type inf={INF,INF};
	const type zero={0,0};
	struct node
	{
		int ch[2],fa,sz,cnt,rev,tag,mnid;
		type v,mn;
	}t[MAX];
	int tot,root;
	type a[MAX];
	queue<int> pool;
	void init_null_node()
	{
		memset(t[0].ch,0,sizeof t[0].ch);
		t[0].sz=t[0].cnt=t[0].fa=0;
		t[0].v=inf;
		t[0].mn=inf;
		t[0].mnid=0;
	}
	void init()
	{
		root=tot=0;
		while(!pool.empty()) pool.pop();
		init_null_node();
		a[0]=a[1]=zero;
		root=build(0,1,0);
	}
	int newnode(type v,int fa)
	{
		int id;
		if(pool.size()>0)
		{
			id=pool.front();
			pool.pop();
		}
		else id=++tot;
		memset(t[id].ch,0,sizeof t[id].ch);
		t[id].fa=fa;
		t[id].sz=t[id].cnt=1;
		t[id].tag=t[id].rev=0;
		t[id].v=t[id].mn=v;
		t[id].mnid=id;
		return id;
	}
	void pushup(int id)
	{
		int ls=t[id].ch[0];
		int rs=t[id].ch[1];
		t[id].sz=t[ls].sz+t[rs].sz+t[id].cnt;
		t[id].mn=t[id].v;
		t[id].mnid=id;
		if(t[ls].mn<t[id].mn)
		{
			t[id].mn=t[ls].mn;
			t[id].mnid=t[ls].mnid;
		}
		else if(t[ls].mn==t[id].mn) t[id].mnid=min(t[id].mnid,t[ls].mnid);
		if(t[rs].mn<t[id].mn)
		{
			t[id].mn=t[rs].mn;
			t[id].mnid=t[rs].mnid;
		}
		else if(t[rs].mn==t[id].mn) t[id].mnid=min(t[id].mnid,t[rs].mnid);
	}
	void pushdown(int id)
	{
		int ls=t[id].ch[0];
		int rs=t[id].ch[1];
		if(t[id].tag)
		{
			if(ls)
			{
				
				t[ls].tag=1;
			}
			if(rs)
			{
				
				t[rs].tag=1;
			}
			t[id].tag=0;
		}
		if(t[id].rev)
		{
			t[ls].rev^=1;
			t[rs].rev^=1;
			swap(t[ls].ch[0],t[ls].ch[1]);
			swap(t[rs].ch[0],t[rs].ch[1]);
			t[id].rev=0;
		}
	}
	void insert(int pos,vector<int> nums)
	{
		int x,y,z,i;
		for(i=0;i<nums.size();i++) a[i+1]={nums[i],pos+i+1};
		z=build(1,nums.size(),0);
		x=find(pos);
		y=find(pos+1);
		splay(x,0);
		splay(y,x);
		t[y].ch[0]=z;
		t[z].fa=y;
		pushup(y);
		pushup(x);
	}
	void rotate(int x)
	{
		int y,z,k;
		y=t[x].fa;
		z=t[y].fa;
		k=(x==t[y].ch[1]);
		t[y].ch[k]=t[x].ch[k^1];
		if(t[x].ch[k^1]) t[t[x].ch[k^1]].fa=y;
		t[x].ch[k^1]=y;
		t[y].fa=x;
		t[x].fa=z;
		if(z) t[z].ch[y==t[z].ch[1]]=x;
		pushup(y);
		pushup(x);
	}
	void splay(int x,int goal)
	{
		int y,z;
		while(t[x].fa!=goal)
		{
			y=t[x].fa;
			z=t[y].fa;
			if(z!=goal)
			{
				if((t[z].ch[0]==y)^(t[y].ch[0]==x)) rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
		if(goal==0) root=x;
	}
	int kth(int k)//k small
	{
		int id=root;
		while(id)
		{
			pushdown(id);
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].cnt>=k) break;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].cnt;
				id=t[id].ch[1];
			}
		}
		splay(id,0);
		return id;
	}
	int find(int x){return kth(x+1);}
	int build(int l,int r,int fa)
	{
		if(l>r) return 0;
		int id,mid;
		mid=(l+r)>>1;
		id=newnode(a[mid],fa);
		t[id].ch[0]=build(l,mid-1,id);
		t[id].ch[1]=build(mid+1,r,id);
		pushup(id);
		return id;
	}
	void _del(int id)
	{
		if(!id) return;
		pool.push(id);
		_del(t[id].ch[0]);
		_del(t[id].ch[1]);
	}
	void erase(int l,int r)
	{
		int x,fa;
		x=split(l,r);
		fa=t[x].fa;
		t[fa].ch[0]=0;
		_del(x);
		pushup(fa);
		pushup(t[fa].fa);
	}
	int split(int l,int r)
	{
		int x,y;
		x=find(l-1);
		y=find(r+1);
		splay(x,0);
		splay(y,x);
		return t[y].ch[0];
	}
	void rev(int l,int r)
	{
		int x,fa;
		x=split(l,r);
		fa=t[x].fa;
		t[x].rev^=1;
		swap(t[x].ch[0],t[x].ch[1]);
		pushup(fa);
		pushup(t[fa].fa);
	}
	int ask_min_id(int l,int r)
	{
		int x=split(l,r);
		return t[x].mnid;
	}
	int ask_pos(int x)
	{
		VI res;
		int now=x;
		while(now)
		{
			res.pb(now);
			now=t[now].fa;
		}
		reverse(all(res));
		for(auto &it:res) pushdown(it);
		splay(x,0);
		return t[t[x].ch[0]].sz;
	}
	int size(){return t[root].sz-2;}
	#undef type
}tr; //tr.init();
int a[MAX];
void go()
{
	int n,i,x;
	while(read(n))
	{
		if(n==0) break;
		read(a,1,n);
		tr.init();
		tr.insert(0,VI(a+1,a+1+n));
		VI res;
		for(i=1;i<=n;i++)
		{
	//		tr.splay_debug();
	//		debug(tr.ask_min_id(i,n))
			x=tr.ask_pos(tr.ask_min_id(i,n));
	//		debug(i,x)
			res.pb(x);
			tr.rev(i,x);
		}
		println(res);
	}
}
