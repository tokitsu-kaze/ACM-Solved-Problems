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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct RMQ
{
	#define type int
	int lg[MAX],bin[22];
	type mx[MAX][22];
	void work(int n,type *v)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++) mx[i][0]=v[i];
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				mx[i][j]=max(mx[i][j-1],mx[i+bin[j-1]][j-1]);
			}
		}
	}
	type ask_max(int l,int r)
	{
		int t=lg[r-l+1];
		return max(mx[l][t],mx[r-bin[t]+1][t]);
	}
	#undef type
}rmq;
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
struct president_tree
{
	#define type int
	int root[MAX],ls[40*MAX],rs[40*MAX],tot,ql,qr;
	type cnt[40*MAX],qv;
	ll sum[MAX*40];
	void init()
	{
		mem(root,0);
		tot=1;
		ls[0]=rs[0]=cnt[0]=0;
		sum[0]=0;
	}
	int newnode(int x)
	{
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		cnt[tot]=cnt[x];
		sum[tot]=sum[x];
		return tot++;
	}
	void insert(int l,int r,int &id,int pre) //set(ql,ql,v)
	{
		id=newnode(pre);
		cnt[id]++;
		sum[id]+=qv;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ql<=mid) insert(l,mid,ls[id],ls[pre]);
		else insert(mid+1,r,rs[id],rs[pre]);
	}
	pair<int,ll> res;
	void query(int l,int r,int id,int pre)
	{
		if(l==r)
		{
			res.fi+=cnt[id]-cnt[pre];
			res.se+=sum[id]-sum[pre];
			return;
		}
		int mid=(l+r)>>1;
		if(qv<=mid)
		{
			res.fi+=cnt[rs[id]]-cnt[rs[pre]];
			res.se+=sum[rs[id]]-sum[rs[pre]];
			query(l,mid,ls[id],ls[pre]);
		}
		else query(mid+1,r,rs[id],rs[pre]);
	}
	pair<int,ll> ask(int l,int r,int v)
	{
		res=MP(0,0);
		ql=l;
		qr=r;
		qv=v;
		query(1,MAX-10,root[r],root[l-1]);
		return res;
	}
	void set(int l,int r,type v=0){ql=l;qr=r;qv=v;}
}pt;
int a[MAX];
ll bit[MAX];
double cal(int l,int r,double mid)
{
	int x;
	x=ceil(mid);
	pair<int,ll> res=pt.ask(l,r,x);
//	debug(x,res.fi,res.se)
//	debug(res.se-mid*res.fi)
	return res.se-mid*res.fi;
}
void go()
{
	int n,q,i,L,R,x,y;
	double l,r,mid,aim;
	while(read(n,q))
	{
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			read(a[i]);
			bit[i]=bit[i-1]+a[i];
		}
		rmq.work(n,a);
		pt.init();
		for(i=1;i<=n;i++)
		{
			pt.set(a[i],a[i],a[i]);
			pt.insert(1,MAX-10,pt.root[i],pt.root[i-1]);
		}
		while(q--)
		{
			read(L,R,x,y);
			aim=(bit[R]-bit[L-1])*1.0/y*x;
			l=0;
			r=rmq.ask_max(L,R);
			while(l+eps<r)
			{
				mid=(l+r)/2;
				if(sgn(cal(L,R,mid)-aim)>=0) l=mid;
				else r=mid;
			}
			printf("%.8f\n",l);
		}
	}
}
