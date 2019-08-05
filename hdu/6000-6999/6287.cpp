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
struct Segment_Tree
{
	int root[MAX],tot,ls[MAX*20],rs[MAX*20],v[MAX*20],ql,qr,qv;
	void init()
	{
		mem(root,0);
		ls[0]=rs[0]=0;
		v[0]=0; 
		tot=1;
	}
	int newnode()
	{
		ls[tot]=rs[tot]=0;
		v[tot]=0;
		return tot++;
	}
	void pushup(int id)
	{
		v[id]=v[ls[id]]+v[rs[id]];
	}
	void insert(int l,int r,int &id,int pos)
	{
		int mid;
		if(!id) id=newnode();
		if(l==r)
		{
			v[id]+=qv;
			return;
		}
		mid=(l+r)>>1;
		if(pos<=mid) insert(l,mid,ls[id],pos);
		else if(pos>=mid+1) insert(mid+1,r,rs[id],pos);
		pushup(id);
	}
	int query(int l,int r,int &id)
	{
		int mid;
		int res=0;
		if(!id) return 0;
		if(l>=ql&&r<=qr) return v[id];
		mid=(l+r)>>1;
		if(ql<=mid) res+=query(l,mid,ls[id]);
		if(qr>mid) res+=query(mid+1,r,rs[id]);
		return res;
	}
}tr;
int prime[MAX];
vector<int> p;
void init(int n)
{
	int i,j;
	mem(prime,0);
	p.clear();
	for(i=2;i<=n;i++)
	{
		if(prime[i]) continue;
		p.pb(i);
		for(j=i+i;j<=n;j+=i)
		{
			if(!prime[j]) prime[j]=i;
		}
	}
}
int n;
void work(int x,int id)
{
	int t,cnt=0;
	while(x>1)
	{
		t=prime[x];
		if(!t)
		{
			tr.qv=1;
			tr.insert(1,n,tr.root[x],id);
			return;
		}
		while(x%t==0&&x>1)
		{
			x/=t;
			cnt++;
		}
		tr.qv=cnt;
		cnt=0;
		tr.insert(1,n,tr.root[t],id);
	}
}
int gao(int x,int l,int r)
{
	int t,cnt=0,flag=0;
	tr.ql=l;
	tr.qr=r;
	while(x>1)
	{
		t=prime[x];
		if(!t)
		{
			tr.qv=1;
			flag|=(tr.query(1,n,tr.root[x])<1);
			return flag;
		}
		while(x%t==0&&x>1)
		{
			x/=t;
			cnt++;
		}
		flag|=(tr.query(1,n,tr.root[t])<cnt);
		cnt=0;
	}
	return flag;
}
void go()
{
	int t,q,i,x,l,r;
	read(t);
	init(MAX-10);
	while(t--)
	{
		read(n,q);
		tr.init();
		for(i=1;i<=n;i++)
		{
			read(x);
			work(x,i);
		}
		while(q--)
		{
			read(l,r,x);
			gao(x,l,r)?puts("No"):puts("Yes");
		}
	}
}
