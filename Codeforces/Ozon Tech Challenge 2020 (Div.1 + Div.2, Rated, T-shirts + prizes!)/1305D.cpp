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
//		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1000+11;
const ll mod=998244353;
/*********************************  head  *********************************/
VI mp[MAX];
int d[MAX],pre[MAX],flag[MAX],cnt,n;
int ask(int a,int b)
{
	cnt++;
	assert(cnt<=n/2);
	cout<<"? "<<a<<" "<<b<<endl;
	int res;
	cin>>res;
	return res;
}
void dfs(int x,int fa,int f)
{
	if(f==0) pre[x]=fa;
	if(f) flag[x]=1;
	for(auto to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,f);
	}
}
void go()
{
	int i,a,b,res,t;
	cnt=0;
	cin>>n;
	for(i=1;i<=n;i++) mp[i].clear();
	mem(d,0);
	for(i=1;i<n;i++)
	{
		cin>>a>>b;
		mp[a].pb(b);
		mp[b].pb(a);
		d[a]++;
		d[b]++;
	}
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(d[i]==1) q.push(i);
	}
	while(sz(q)>=2)
	{
		while(sz(q)&&flag[q.front()]) q.pop();
		if(sz(q)>=2)
		{
			a=q.front();
			q.pop();
		}
		else break;
		while(sz(q)&&flag[q.front()]) q.pop();
		if(sz(q))
		{
			b=q.front();
			q.pop();
		}
		else
		{
			cout<<"! "<<a<<endl;
			return;
		}
		res=ask(a,b);
		if(res==a||res==b)
		{
			cout<<"! "<<res<<endl;
			return;
		}
		dfs(res,0,0);
		t=a;
		while(1)
		{
			if(t==res) break;
			t=pre[t];
			d[t]--;
			flag[t]=1;
		}
		t=a;
		while(1)
		{
			t=pre[t];
			if(t==res) break;
			for(auto to:mp[t])
			{
				if(flag[to]) continue;
				dfs(to,t,1);
			}
		}
		t=b;
		while(1)
		{
			if(t==res) break;
			t=pre[t];
			d[t]--;
			flag[t]=1;
		}
		t=b;
		while(1)
		{
			t=pre[t];
			if(t==res) break;
			for(auto to:mp[t])
			{
				if(flag[to]) continue;
				dfs(to,t,1);
			}
		}
		flag[res]=0;
		if(d[res]<=1) q.push(res);
	}
	if(sz(q)==1)
	{
		cout<<"! "<<q.front()<<endl;
	}
}
