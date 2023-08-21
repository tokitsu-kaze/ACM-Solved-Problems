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
const ll mod=998244353;
/*********************************  head  *********************************/
int v[MAX],maxx[MAX][20];
void RMQ(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		maxx[i][0]=v[i];
		for(j=1;1<<(j-1)<=n;j++) maxx[i][j]=0;
	}
	for(j=1;1<<(j-1)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			int t=1<<(j-1);
			maxx[i][j]=max(maxx[i][j-1],maxx[i+t][j-1]);
		}
	}
}
int query(int l,int r)
{
	int j=(int)(log10(r-l+1)/log10(2))+1;
	int i=r-(1<<(j-1))+1;
	return max(maxx[l][j-1],maxx[i][j-1]);
}
struct node
{
	int x,v,id;
	void input(int i)
	{
		read(x,v);
		id=i;
	}
	friend bool operator<(node a,node b){return a.x<b.x;}
}qs[MAX];
int ans[MAX],dp[MAX];
void go()
{
	int t,i,j,n,q,now,mx,pos;
	read(t);
	while(t--)
	{
		read(n,q);
		for(i=1;i<=n;i++) read(v[i]);
		RMQ(n);
		auto getpos=[&](int _l,int _r,int v)->int
		{
			int l,r,mid;
			l=_l;
			r=_r;
			if(l>r) return -1;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(query(l,mid)<=v) l=mid+1;
				else r=mid;
			}
			if(query(l,l)<=v) return -1;
			return l;
		};
		dp[n]=1;
		for(i=n-1;i;i--)
		{
			pos=getpos(i+1,n,v[i]);
			if(pos!=-1) dp[i]=dp[pos]+1;
			else dp[i]=1;
		}
		for(i=1;i<=q;i++) qs[i].input(i);
		sort(qs+1,qs+1+q);
		now=0;
		mx=-1;
		for(i=1,j=1;i<=q;i++)
		{
			while(j<qs[i].x)
			{
				if(v[j]>mx)
				{
					mx=v[j];
					now++;
				}
				j++;
			}
			ans[qs[i].id]=now;
			if(qs[i].v>mx)
			{
				pos=getpos(j+1,n,qs[i].v);
				ans[qs[i].id]++;
			}
			else pos=getpos(j+1,n,mx);
			if(pos!=-1) ans[qs[i].id]+=dp[pos];
		}
		for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
}

