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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node{int x,id;};
vector<node> mp[MAX];
set<int> s[MAX];
int fa[MAX],d[MAX],mx,h[MAX],flag[MAX];
void dfs(int x,int pre,int dep)
{
	s[dep].insert(x);
	fa[x]=pre;
	h[x]=dep;
	mx=max(mx,dep);
	for(auto &to:mp[x])
	{
		if(to.x==pre) continue;
		dfs(to.x,x,dep+1);
	}
}
void go()
{
	int t,n,i,a,b,ok,x;
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++)
		{
			d[i]=flag[i]=0;
			mp[i].clear();
			s[i].clear();
		}
		for(i=1;i<n;i++)
		{
			read(a,b);
			mp[a].pb({b,i});
			mp[b].pb({a,i});
			d[a]++;
			d[b]++;
		}
		mx=0;
		fa[0]=0;
		h[0]=0;
		dfs(1,0,1);
		ok=1;
		VI res;
		while(mx>0)
		{
			set<int> tmp;
			for(auto &it:s[mx])
			{
				if(fa[it]==0) continue;
				if(flag[fa[it]]) continue;
				tmp.insert(fa[it]);
	//			debug(it,fa[it])
			}
			VI tmp2;
			for(auto &it:tmp)
			{
				if(d[it]>3 || (d[it]==3 && it==1))
				{
					ok=0;
					break;
				}
				else if(d[it]==3 || (d[it]==2 && it==1))
				{
					for(auto &to:mp[it])
					{
						if(flag[to.x]) continue;
						if(s[h[it]+1].count(to.x))
						{
							s[h[to.x]].erase(to.x);
							flag[to.x]=1;
						}
						else res.pb(to.id);
						d[it]--;
						d[to.x]--;
					}
					s[h[it]].erase(it);
					flag[it]=1;
				}
				else
				{
	//				debug(it,d[it])
					tmp2.pb(it);
					continue;
				}
			}
			for(auto &it:tmp2)
			{
				x=fa[it];
				if(x==0) continue;
				if(flag[x]) continue;
				if(d[x]>2)
				{
					ok=0;
					break;
				}
				for(auto &to:mp[x])
				{
					if(flag[to.x]) continue;
					if(to.x==it)
					{
						s[h[to.x]].erase(to.x);
						flag[it]=1;
					}
					else res.pb(to.id);
					d[x]--;
					d[to.x]--;
				}
				flag[x]=1;
				for(auto &to:mp[it])
				{
					if(s[h[to.x]].count(to.x))
					{
						flag[to.x]=1;
						s[h[to.x]].erase(to.x);
						d[it]--;
						d[to.x]--;
					}
				}
			}
			if(sz(s[mx])) ok=0;
	//		debug(mx,sz(s[mx]))
	//		for(auto &it:s[mx]) debug(it)
			if(!ok) break;
			mx--;
		}
		if(ok==0) puts("-1");
		else
		{
			sort(all(res));
			res.resize(unique(all(res))-res.begin()); 
			printf("%d\n",sz(res));
			println(res);
			if(sz(res)==0) puts("");
		}
	}
}
/*
5
3 2
3 5
1 5
4 1
4
1 2
1 3
1 4

*/
