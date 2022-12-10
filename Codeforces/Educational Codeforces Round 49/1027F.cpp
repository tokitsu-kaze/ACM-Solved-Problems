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
#define _GLIBCXX_PERMIT_BACKWARD_HASH
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
const int MAX=2e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct dsu
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	int merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb) pre[ra]=rb;
		if(ra!=rb) return 0;
		else return ra;
	}
}dsu;
int cnt[MAX],v[MAX],belong[MAX];
priority_queue<int> q[MAX];
void go()
{
	int n,i,a,b,tot,tmp,ans,flag;
	while(read(n))
	{
		tot=0;
		hash_map<int,int> mp;
		dsu.init(2*n);
		for(i=1;i<=2*n;i++) belong[i]=cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			read(a,b);
			if(!mp[a])
			{
				mp[a]=++tot;
				v[tot]=a;
			}
			a=mp[a];
			if(!mp[b])
			{
				mp[b]=++tot;
				v[tot]=b;
			}
			b=mp[b];
			tmp=dsu.merge(a,b);
			if(tmp) belong[tmp]++;
		}
		for(i=1;i<=tot;i++) cnt[dsu.find(i)]+=belong[i];
		flag=0;
		for(i=1;i<=tot;i++)
		{
			if(cnt[i]>=2) flag=1;
			while(!q[i].empty()) q[i].pop();
		}
		if(flag)
		{
			puts("-1");
			continue;
		}
		ans=0;
		for(i=1;i<=tot;i++)
		{
			tmp=dsu.find(i);
			if(sz(q[tmp])<2) q[tmp].push(-v[i]);
			else
			{
				if(v[i]>-q[tmp].top())
				{
					q[tmp].pop();
					q[tmp].push(-v[i]);
				}
			}
		}
		for(int it=1;it<=tot;it++)
		{
			if(sz(q[it])==0) continue;
			tmp=q[it].top();
			q[it].pop();
			if(cnt[it]==0)
			{
				if(sz(q[it])>=1) ans=max(ans,-tmp);
				else ans=max(ans,-q[it].top());
			}
			else if(cnt[it]==1) ans=max(ans,-q[it].top());
		}
		printf("%d\n",ans);
	}
}
