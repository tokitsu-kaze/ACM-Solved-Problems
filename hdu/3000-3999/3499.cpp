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
#define _BACKWARD_BACKWARD_WARNING_H
#include <ext/hash_map>
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
struct node
{
	int id,k;
	ll v;
	node(){}
	node(int a,ll b,int _k=0) :id(a),v(b),k(_k){}
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
vector<node> mp[MAX];
bool flag[MAX][2];
ll dis[MAX][2];
void dij(int s)
{
	int i;
	priority_queue<node> q;
	node t,to;
	mem(dis,0x3f);
	mem(flag,0);
	dis[s][0]=0;
	q.push(node(s,0,0));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id][t.k]) continue;
		flag[t.id][t.k]=1;
		for(i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			if(dis[to.id][t.k]>dis[t.id][t.k]+to.v)
			{
				dis[to.id][t.k]=dis[t.id][t.k]+to.v;
				q.push(node(to.id,dis[to.id][t.k],t.k));
			}
			if(t.k+1<=1&&dis[to.id][t.k+1]>dis[t.id][t.k]+to.v/2)
			{
				dis[to.id][t.k+1]=dis[t.id][t.k]+to.v/2;
				q.push(node(to.id,dis[to.id][t.k+1],t.k+1));
			}
		}
	}
}
void go()
{
	int n,m,i,a,b,tot;
	ll v;
	char s[111];
	while(read(n,m))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		tot=0;
		unordered_map<string,int> ha;
		while(m--)
		{
			read(s);
			if(!ha[s]) ha[s]=++tot;
			a=ha[s];
			read(s);
			if(!ha[s]) ha[s]=++tot;
			b=ha[s];
			read(v);
			mp[a].pb(node(b,v));
		}
		read(s);
		if(!ha[s]) ha[s]=++tot;
		a=ha[s];
		dij(a);
		read(s);
		if(!ha[s]) ha[s]=++tot;
		b=ha[s];
		ll ans=LLINF;
		ans=min({ans,dis[b][0],dis[b][1]});
		if(ans==LLINF) ans=-1;
		printf("%lld\n",ans);
	}
}
