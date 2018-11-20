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
struct high_level_preflow_push
{
	static const int N=100010;
	struct node{int v,cap,index;};
	vector<node> edge[N];
	vector<int> List[N];
	vector<list<int>::iterator> listit;
	list<int> dlist[N];
	int highest,highestActive,vis[N],excess[N],height[N],n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) edge[i].clear();
	}
	void add(int u,int v,int cap)
	{
		edge[u].push_back(node{v,cap,edge[v].size()});
		edge[v].push_back(node{u,cap,edge[u].size()-1});
	}
	void globalRelabel(int t)
	{
		int u,i,hp,v,index;
		queue<int> q;
		for(i=0;i<=n;i++)
		{
			height[i]=n;
			List[i].clear();
			dlist[i].clear();
			vis[i]=0;
		}
		height[t]=0;
		q.push(t);
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			for(i=0;i<edge[u].size();i++)
			{
				v=edge[u][i].v;
				index=edge[u][i].index;
				if(height[v]==n&&edge[v][index].cap>0)
				{
					height[v]=height[u]+1;
					vis[height[v]]++;
					q.push(hp=v);
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(height[i]<n)
			{
				listit[i]=dlist[height[i]].insert(dlist[height[i]].begin(),i);
				if(excess[i]>0) List[height[i]].push_back(i);
			}
		}
		highest=height[hp];
		highestActive=height[hp];
	}
	void push(int u,node &e)
	{
		int v,df;
		v=e.v;
		df=min(excess[u],e.cap);
		e.cap=e.cap-df;
		edge[v][e.index].cap=edge[v][e.index].cap+df;
		excess[u]=excess[u]-df;
		excess[v]=excess[v]+df;
		if(excess[v]>0&&excess[v]<=df) List[height[v]].push_back(v);
	}
	void discharge(int u)
	{
		int i,nh,v,cap,h;
		nh=n;
		for(i=0;i<edge[u].size();i++)
		{
			v=edge[u][i].v;
			cap=edge[u][i].cap;
			if(cap>0)
			{
				if(height[u]==height[v]+1)
				{
					push(u,edge[u][i]);
					if(excess[u]==0) return;
				}
				else nh=min(nh,height[v]+1);
			}
		}
		h=height[u];
		if(vis[h]==1)
		{
			for(i=h;i<=highest;i++)
			{
				for(list<int>::iterator it=dlist[i].begin();it!=dlist[i].end();it++)
				{
					vis[height[*it]]--;
					height[*it]=n;
				}
				dlist[i].clear();
			}
			highest=h-1;
		}
		else
		{
			vis[h]--;
			listit[u]=dlist[h].erase(listit[u]);
			height[u]=nh;
			if(nh==n) return;
			vis[nh]++;
			listit[u]=dlist[nh].insert(dlist[nh].begin(),u);
			highestActive=nh;
			highest=max(highest,highestActive);
			List[nh].push_back(u);
		}
	}
	int maxflow(int s,int e)
	{
		int i,u;
		if(s==e) return 0;
		highestActive=0;
		highest=0;
		for(i=0;i<=n;i++) height[i]=vis[i]=excess[i]=0;
		height[s]=n;
		listit.resize(n);
		for(i=0;i<n;i++)
		{
			if(i!=s)
			{
				listit[i]=dlist[height[i]].insert(dlist[height[i]].begin(),i);
			}
		}
		vis[0]=n-1;
		excess[s]=INF;
		excess[e]=-INF;
		for(i=0;i<edge[s].size();i++) push(s,edge[s][i]);
		globalRelabel(e);
		while(highestActive>=0)
		{
			if(List[highestActive].empty()==1)
			{
				highestActive--;
				continue;
			}
			u=List[highestActive].back();
			List[highestActive].pop_back();
			discharge(u);
		}
		return excess[e]+INF;
	}
}hlpp;
void go()
{
	int T,s,t,x,y,i,mx,mn,a,b,w,n,m;
	read(T);
	while(T--)
	{
		mn=INF;
		mx=-INF;
		read(n,m);
		hlpp.init(n);
		for(i=1;i<=n;i++)
		{
			read(x,y);
			if(x<mn)
			{
				s=i;
				mn=x;
			}
			if(x>mx)
			{
				t=i;
				mx=x;
			}
		}
		while(m--)
		{
			read(a,b,w);
			hlpp.add(a,b,w);
		}
		debug(s,t)
		printf("%d\n",hlpp.maxflow(s,t));
	}
}
