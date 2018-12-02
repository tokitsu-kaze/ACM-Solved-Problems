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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node
{
	int id;
	ll v;
	node(){}
	node(int a,ll b) :id(a),v(b){}
	friend bool operator <(node a,node b){return a.v>b.v;}
};
vector<node> mp[2][MAX];
bool flag[MAX];
ll dis[2][MAX],cnt[2][MAX];
int n;
void dij(int f,int s)
{
	int i;
	priority_queue<node> q;
	node t,to;
	mem(dis[f],0x3f);
	mem(flag,0);
	mem(cnt[f],0);
	cnt[f][s]=1;
	dis[f][s]=0;
	q.push(node(s,0));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id]) continue;
		flag[t.id]=1;
		for(i=0;i<sz(mp[f][t.id]);i++)
		{
			to=mp[f][t.id][i];
			if(dis[f][to.id]>dis[f][t.id]+to.v)
			{
				cnt[f][to.id]=cnt[f][t.id];
				dis[f][to.id]=dis[f][t.id]+to.v;
				q.push(node(to.id,dis[f][to.id]));
			}
			else if(dis[f][to.id]==dis[f][t.id]+to.v)
			{
				cnt[f][to.id]+=cnt[f][t.id];
				cnt[f][to.id]%=mod;
			}
		}
	}
}
struct edge
{
	int a,b,w;
	void input(){read(a,b,w);}
}e[MAX];
void go()
{
	int m,i;
	while(read(n,m))
	{
		debug("case")
		for(i=1;i<=n;i++)
		{
			mp[0][i].clear();
			mp[1][i].clear();
			cnt[0][i]=cnt[1][i]=0;
		}
		for(i=1;i<=m;i++)
		{
			e[i].input();
			mp[0][e[i].a].pb(node(e[i].b,e[i].w));
			mp[1][e[i].b].pb(node(e[i].a,e[i].w));
		}
		dij(0,1);
		dij(1,2);
		for(i=1;i<=m;i++)
		{
			if(dis[0][e[i].a]+dis[1][e[i].b]+e[i].w==dis[0][2])
			{
				if(cnt[1][e[i].b]*cnt[0][e[i].a]%mod==cnt[0][2]) puts("SAD");
				else puts("SOSO");
			}
			else
			{
				if(dis[0][e[i].b]+dis[1][e[i].a]+e[i].w<dis[0][2]) puts("HAPPY");
				else puts("SOSO");
			}
		}
	}
}
