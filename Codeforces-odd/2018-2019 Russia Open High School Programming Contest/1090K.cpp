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
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node
{
	int id;
	string a,b;
	friend bool operator==(node a,node b)
	{
		return a.a==b.a&&a.b==b.b;
	}
	friend bool operator<(node a,node b)
	{
		if(a.b==b.b) return a.a<b.a;
		return a.b<b.b;
	}
};
char a[MAX],b[MAX];
int fa[MAX];
VI ans[MAX];
void go()
{
	int n,i,j,cnt;
	node tmp;
	while(read(n))
	{
		vector<node> res;
		string now;
		for(i=0;i<n;i++)
		{
			fa[i]=i;
			ans[i].clear();
			read(a,b);
			tmp.id=i;
			tmp.a=string(a);
			tmp.b=string(b);
			now="";
			sort(all(tmp.b));
			tmp.b.resize(unique(all(tmp.b))-tmp.b.begin());
			for(j=sz(tmp.a)-1;~j;j--)
			{
				if(tmp.b.find(tmp.a[j])==string::npos)
				{
					now=tmp.a.substr(0,j+1);
					break;
				}
			}
			tmp.a=now;
			res.pb(tmp);
		}
		sort(all(res));
		string ra,rb;
		for(i=1;i<n;i++)
		{
			if(res[i]==res[i-1]) fa[res[i].id]=fa[res[i-1].id];
		}
		for(i=0;i<n;i++) ans[fa[i]].pb(i);
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(sz(ans[i])) cnt++;
		}
		printf("%d\n",cnt);
		for(i=0;i<n;i++)
		{
			if(!sz(ans[i])) continue;
			printf("%d",sz(ans[i]));
			for(j=0;j<sz(ans[i]);j++) printf(" %d",ans[i][j]+1);
			puts("");
		}
	}
}