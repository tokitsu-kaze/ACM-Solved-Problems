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
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct node
{
	int fi,se;
	node(){}
	node(int l,int r) :fi(l),se(r){}
	friend bool operator<(node a,node b)
	{
		if(a.fi==b.fi) return a.se<b.se;
		return a.fi>b.fi;
	}
	friend bool operator!=(node a,node b)
	{
		return a.fi!=b.fi||a.se!=b.se;
	}
};
set<node> mp[MAX];
PII a[MAX];
int res[MAX],nex[MAX],p[MAX];
void go()
{
	int t,n,m,i,ans,x,tot,time,cas=1;
	node tmp;
	ll pre,now;
	read(t);
	while(t--)
	{
		unordered_map<int,int> id;
		VI xx;
		read(n,m);
		for(i=1;i<=n;i++)
		{
			read(a[i].fi,a[i].se);
			xx.pb(a[i].fi);
			res[i]=0;
			nex[i]=i+1;
			p[i]=i-1;
		}
		sort(all(xx));
		xx.resize(unique(all(xx))-xx.begin());
		for(i=0;i<sz(xx);i++) id[xx[i]]=i+1;
		tot=sz(xx);
		for(i=1;i<=tot;i++) mp[i].clear();
		for(i=1;i<=n;i++) mp[id[a[i].fi]].insert(node(a[i].se,i));
		pre=0;
		printf("Case #%d:\n",cas++);
		for(time=1;time<=m;time++)
		{
			read(x);
			x=(x^pre);
			ans=0;
			now=1;
			for(i=1;i<=tot;i=nex[i])
			{
				if(xx[i-1]>x) break;
				tmp=node(-INF,-INF);
				for(auto &it:mp[i])
				{
					if(tmp!=node(-INF,-INF)) mp[i].erase(tmp);
					if(it.fi<x) break;
					ans++;
					res[it.se]=time;
					now=now*it.se%mod;
					tmp=it;
				}
				if(tmp!=node(-INF,-INF)) mp[i].erase(tmp);
				if(sz(mp[i])==0)
				{
					nex[p[i]]=nex[i];
					p[nex[i]]=p[i];
				}
			}
			if(now==1&&res[1]!=time) now=0;
			pre=now;
			printf("%d\n",ans);
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
}


