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
const double eps=1e-8;
const int MAX=1e5+10;
const int mod=1e9+7;
/*********************************  head  *********************************/
struct president_tree
{
	#define type int
	int root[MAX],ls[40*MAX],rs[40*MAX],tot,ql,qr;
	type sum[40*MAX],qv;
	void init()
	{
		mem(root,0);
		tot=1;
		ls[0]=rs[0]=sum[0]=0;
	}
	int newnode(int x)
	{
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		sum[tot]=sum[x];
		return tot++;
	}
	void insert(int l,int r,int &id,int pre) //set(ql,ql,v)
	{
		id=newnode(pre);
		sum[id]+=qv;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ql<=mid) insert(l,mid,ls[id],ls[pre]);
		else insert(mid+1,r,rs[id],rs[pre]);
	}
	int kthbig(int l,int r,int id,int pre,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		int temp=sum[rs[id]]-sum[rs[pre]];
		if(temp>=k) return kthbig(mid+1,r,rs[id],rs[pre],k);
		else return kthbig(l,mid,ls[id],ls[pre],k-temp);
	}
	void set(int l,int r,type v=0){ql=l;qr=r;qv=v;}
}pt;
struct Discretization
{
	#define type int
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.pb(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_id(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
}di;
int a[MAX];
void go()
{
	int n,q,i,l,r,pos,mx;
	ll ans;
	while(read(n,q))
	{
		di.init();
		for(i=1;i<=n;i++)
		{
			read(a[i]);
			di.add(a[i]);
		}
		pt.init();
		di.work();
		for(i=1;i<=n;i++)
		{
			pos=di.get_id(a[i]);
			pt.set(pos,pos,1);
			pt.insert(1,n,pt.root[i],pt.root[i-1]);
		}
		VL res(46);
		while(q--)
		{
			read(l,r);
			mx=min(45,r-l+1);
			ans=-1;
			for(i=1;i<=mx;i++)
			{
				res[i]=di.get_val(pt.kthbig(1,n,pt.root[r],pt.root[l-1],i));
				if(i-2>=1)
				{
					if(res[i-1]+res[i]>res[i-2])
					{
						ans=res[i-2]+res[i-1]+res[i];
						break;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
}
