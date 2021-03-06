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
VI mp[MAX],leaf;
int fa[MAX],v[MAX];
void dfs(int x,int pre)
{
	fa[x]=pre;
	for(auto to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
	}
	if(x>1&&sz(mp[x])==1) leaf.pb(x);
}
int ans[MAX],l[MAX<<1],r[MAX<<1];
int flag[MAX];
void go()
{
	int t,i,n,a,b,mx,dep,x,cnt;
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++)
		{
			read(v[i]);
			mp[i].clear();
		}
		for(i=1;i<n;i++)
		{
			read(a,b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		if(n==1)
		{
			puts("0");
			continue;
		}
		leaf.clear();
		dfs(1,0);
		mem(ans,-1);
		mem(flag,0);
		mem(l,0);
		mem(r,0);
		VI cl,tmp[2];
		for(auto it:leaf)
		{
			mx=0;
			dep=1;
			x=it;
			while(sz(mp[x])-(x>1)<=1&&x)
			{
				
				cl.pb(v[x]+dep);
				cl.pb(v[x]-dep+100000);
//				debug(x,v[x]+dep,l[v[x]+dep],v[x]-dep+100000,r[v[x]-dep+100000])
				mx=max({mx,++l[v[x]+dep],++r[v[x]-dep+100000]});
				ans[x]=dep-mx;
//				debug(x,mx)
				dep++;
				flag[x]=1;
				x=fa[x];
			}
			for(auto tt:cl) l[tt]=r[tt]=0;
			cl.clear();
			if(sz(mp[x])-(x>1)!=2) continue;
			cnt=0;
			tmp[0].clear();
			tmp[1].clear();
			for(auto to:mp[x])
			{
				if(to==fa[x]) continue;
				tmp[cnt++].pb(to);
			}
			if(flag[tmp[0][0]]+flag[tmp[1][0]]<2) continue;
			x=tmp[0][0];
			while(sz(mp[x])-1==1)
			{
				for(auto to:mp[x])
				{
					if(to==fa[x]) continue;
					tmp[0].pb(to);
				}
				x=tmp[0][sz(tmp[0])-1];
			}
			x=tmp[1][0];
			while(sz(mp[x])-1==1)
			{
				for(auto to:mp[x])
				{
					if(to==fa[x]) continue;
					tmp[1].pb(to);
				}
				x=tmp[1][sz(tmp[1])-1];
			}
			reverse(all(tmp[0]));
			x=it;
			while(sz(mp[x])-(x>1)<=1&&x) x=fa[x];
			tmp[0].pb(x);
			for(auto tt:tmp[1]) tmp[0].pb(tt);
			mx=0;
			dep=1;
	//		debug(tmp[0])
			for(auto tt:tmp[0])
			{
				cl.pb(v[tt]+dep);
				cl.pb(v[tt]-dep+100000);
				mx=max({mx,++l[v[tt]+dep],++r[v[tt]-dep+100000]});
				dep++;
			}
			ans[x]=sz(tmp[0])-mx;
			for(auto tt:cl) l[tt]=r[tt]=0;
			cl.clear();
		}
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
}