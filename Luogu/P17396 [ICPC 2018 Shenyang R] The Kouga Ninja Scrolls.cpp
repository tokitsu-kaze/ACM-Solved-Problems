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
	#define type PLL
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],mx[2][MAX<<2],mn[2][MAX<<2];
	type rmx[2],rmn[2];
	void upmx(int id)
	{
		ll tx[4]={mx[0][id].fi,mx[1][id].fi,rmx[0].fi,rmx[1].fi};
		ll tc[4]={mx[0][id].se,mx[1][id].se,rmx[0].se,rmx[1].se};
		int idx[4]={0,1,2,3},cnt=0;
		sort(idx,idx+4,[&](int a,int b){return tx[a]>tx[b];});
		for(int i=0;i<4&&cnt<2;i++)
		{
			if(i==0||tc[idx[i]]!=tc[idx[i-1]])
			{
				rmx[cnt].fi=tx[idx[i]];
				rmx[cnt++].se=tc[idx[i]];
			}
		}
		for(int i=cnt;i<2;i++)
		{
			rmx[i].fi=-LLINF;
			rmx[i].se=-LLINF;
		}
	}
	void upmn(int id)
	{
		ll tx[4]={mn[0][id].fi,mn[1][id].fi,rmn[0].fi,rmn[1].fi};
		ll tc[4]={mn[0][id].se,mn[1][id].se,rmn[0].se,rmn[1].se};
		int idx[4]={0,1,2,3},cnt=0;
		sort(idx,idx+4,[&](int a,int b){return tx[a]<tx[b];});
		for(int i=0;i<4&&cnt<2;i++)
		{
			if(i==0||tc[idx[i]]!=tc[idx[i-1]])
			{
				rmn[cnt].fi=tx[idx[i]];
				rmn[cnt++].se=tc[idx[i]];
			}
		}
		for(int i=cnt;i<2;i++)
		{
			rmn[i].fi=LLINF;
			rmn[i].se=-LLINF;
		}
	}
	void pushup(int id)
	{
		mx[0][id]=mx[0][ls];
		rmx[0]=mx[0][rs];
		mx[1][id]=mx[1][ls];
		rmx[1]=mx[1][rs];
		upmx(id);
		mx[0][id]=rmx[0];
		mx[1][id]=rmx[1];
		
		mn[0][id]=mn[0][ls];
		rmn[0]=mn[0][rs];
		mn[1][id]=mn[1][ls];
		rmn[1]=mn[1][rs];
		upmn(id);
		mn[0][id]=rmn[0];
		mn[1][id]=rmn[1];
	}
	void build(int l,int r,int id)
	{
		mx[1][id]=MP(-LLINF,-LLINF);
		mn[1][id]=MP(LLINF,-LLINF);
		if(l==r)
		{
			mx[0][id]=mn[0][id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		mx[1][id]=MP(-LLINF,-LLINF);
		mn[1][id]=MP(LLINF,-LLINF);
		if(l>=ql&&r<=qr)
		{
			mx[0][id]=mn[0][id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			upmx(id);
			upmn(id);
			return ;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r)
	{
		ql=l;
		qr=r;
		update(1,n,1);
	}
	ll ask(int l,int r)
	{
		rmx[0]=rmx[1]=MP(-LLINF,-LLINF);
		rmn[0]=rmn[1]=MP(LLINF,-LLINF);
		ql=l;
		qr=r;
		query(1,n,1);
		ll res=0;
		if(rmx[0].se!=rmn[0].se) res=max(res,rmx[0].fi-rmn[0].fi);
		if(rmn[1].se!=-LLINF&&rmx[0].se!=rmn[1].se) res=max(res,rmx[0].fi-rmn[1].fi);
		if(rmx[1].se!=-LLINF&&rmx[1].se!=rmn[0].se) res=max(res,rmx[1].fi-rmn[0].fi);
		if(rmx[1].se!=-LLINF&&rmn[1].se!=-LLINF&&rmx[1].se!=rmn[1].se) res=max(res,rmx[1].fi-rmn[1].fi);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tx,ty;
void go()
{
	int t,cas=1,n,q,i,op,l,r;
	ll x,y,c,k;
	read(t);
	while(t--)
	{
		read(n,q);
		for(i=1;i<=n;i++)
		{
			read(x,y,c);
			tx.a[i]=MP(x+y,c);
			ty.a[i]=MP(x-y,c);
		}
		tx.build(n);
		ty.build(n);
		printf("Case #%d:\n",cas++);
		while(q--)
		{
			read(op);
			if(op==1)
			{
				read(k,x,y);
				tx.a[k].fi+=x+y;
				ty.a[k].fi+=x-y;
				tx.upd(k,k);
				ty.upd(k,k);
			}
			else if(op==2)
			{
				read(k,c);
				tx.a[k].se=c;
				ty.a[k].se=c;
				tx.upd(k,k);
				ty.upd(k,k);
			}
			else
			{
				read(l,r);
				printf("%lld\n",max(tx.ask(l,r),ty.ask(l,r)));
			}
		}
	}
}