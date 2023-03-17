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
void assert_lr(ll x,ll l,ll r) {assert(x>=l&&x<=r);};
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
struct Discretization
{
	#define type ll
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.pb(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
}d;
set<int> setid[MAX];
set<PII > rest[MAX];
void go()
{
	int m,n,i,j,x,ok,f,value,now;
	PII pos;
	while(read(m))
	{
		map<int,int> mp;
		vector<VI > res;
		d.init();
		for(i=1;i<=m;i++)
		{
			read(n);
			VI tmp;
			while(n--)
			{
				read(x);
				mp[x]++;
				tmp.pb(x);
				d.add(x);
			}
			res.pb(tmp);
		}
		d.work();
		for(i=1;i<=sz(d);i++) setid[i].clear();
		ok=1;
		for(auto it:mp)
		{
			if(it.se%2==1) ok=0;
		}
		if(!ok)
		{
			puts("NO");
			continue;
		}
		vector<string > ans;
		j=0;
		for(auto tmp:res)
		{
			string s=string(sz(tmp),'.');
			mp.clear();
			for(i=0;i<sz(tmp);i++)
			{
				if(mp[tmp[i]])
				{
					s[mp[tmp[i]]-1]='L';
					s[i]='R';
					mp[tmp[i]]=0;
				}
				else mp[tmp[i]]=i+1;
			}
			rest[j].clear();
			for(i=0;i<sz(tmp);i++)
			{
				if(s[i]=='.') 
				{
					rest[j].insert(MP(d.get_pos(tmp[i]),i));
					setid[d.get_pos(tmp[i])].insert(j);
					debug(j,MP(d.get_pos(tmp[i]),i))
				}
			}
			ans.pb(s);
			j++;
		}
		for(i=1;i<=sz(d);i++)
		{
			f=0;
			debug(i)
			while(sz(setid[i])>0)
			{
				x=*(setid[i].begin());
				setid[i].erase(x);
				pos=*(rest[x].lower_bound(MP(i,-1)));
				rest[x].erase(pos);
				debug(x,pos)
				if(f==0) ans[x][pos.se]='L';
				else ans[x][pos.se]='R';
				f^=1;
				
				now=*(setid[pos.fi].begin());
				setid[pos.fi].erase(now);
				pos=*(rest[now].lower_bound(MP(pos.fi,-1)));
				rest[now].erase(pos);
				debug(now,pos)
				if(f==0) ans[now][pos.se]='L';
				else ans[now][pos.se]='R';
				f^=1;
				
				pos=*(rest[now].begin());
				while(1)
				{
					debug(pos)
					setid[pos.fi].erase(now);
					rest[now].erase(pos);
					debug(now,pos)
					if(f==0) ans[now][pos.se]='L';
					else ans[now][pos.se]='R';
					f^=1;
					
					now=*(setid[pos.fi].begin());
					setid[pos.fi].erase(now);
					pos=*(rest[now].lower_bound(MP(pos.fi,-1)));
					rest[now].erase(pos);
					debug(now,pos)
					if(f==0) ans[now][pos.se]='L';
					else ans[now][pos.se]='R';
					f^=1;
					if(now==x) break;
					
					pos=*(rest[now].begin());
				}
			}
		}
		puts("YES");
		for(auto it:ans) cout<<it<<"\n";
	}
}

