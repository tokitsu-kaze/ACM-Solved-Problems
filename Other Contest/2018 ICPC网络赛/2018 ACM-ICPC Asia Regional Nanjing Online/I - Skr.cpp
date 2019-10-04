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
const int MAX=2e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct BKDRHash
{
	static const ull seed=1313131;//31,131,1313,13131,131313
	static const int p=2000007;
	ull Hash[MAX],tmp[MAX];
	ull val[MAX];
	int last[p+10],nex[MAX],cnt;
	void init()//clear hash table 
	{
		mem(last,0);
		cnt=0;
	}
	bool insert(ull x)
	{
		int u=x%p;
		for(int i=last[u];i;i=nex[i])
		{
			if(val[i]==x) return 1;
		}
		nex[++cnt]=last[u];
		last[u]=cnt;
		val[cnt]=x;
		return 0;
	}
	void work(char *s,int n)
	{
		tmp[0]=1;
		Hash[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=tmp[i-1]*seed;
			Hash[i]=Hash[i-1]*seed+s[i];
		}
	}
	ull get(int l,int r)
	{
		return Hash[r]-Hash[l-1]*tmp[r-l+1];
	}
}bkdr; //bkdr.init();
struct hash_table
{
	ll seed,p;
	ll Hash[MAX],tmp[MAX];
	void set(ll _seed,ll _p)
	{
		seed=_seed;
		p=_p;
	}
	void work(char *s,int n)
	{
		tmp[0]=1;
		Hash[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=tmp[i-1]*seed%p;
			Hash[i]=(Hash[i-1]*seed+(s[i]-'0'))%p;
		}
	}
	ll get(int l,int r)
	{
		return ((Hash[r]-Hash[l-1]*tmp[r-l+1])%p+p)%p;
	}
}ha;
ll ans;
void gao(int l,int r)
{
    if(!bkdr.insert(bkdr.get(l,r))) ans=(ans+ha.get(l,r))%mod;
} 
struct Manacher
{
	int r[MAX];
	int work(char *s,int len)//return max length of palindrome
	{
		int right,mid,i,res=0;
		//odd
		bkdr.init();
		right=mid=0;
		mem(r,0); 
		for(i=1;i<=len;i++)
		{
			//substring s[i,i]
			gao(i,i);
			if(right>i) r[i]=min(r[2*mid-i],right-i);
			while(i+r[i]+1<=len&&s[i+r[i]+1]==s[i-r[i]-1])
			{
				//substring s[i-r[i]-1,i+r[i]+1]
				gao(i-r[i]-1,i+r[i]+1);
				r[i]++;
			}
			if(i+r[i]>right)
			{
				right=i+r[i];
				mid=i;
			}
			res=max(res,r[i]*2+1);
		}
		//even
		bkdr.init();
		right=mid=0;
		mem(r,0);
		for(i=2;i<=len;i++)
		{
			if(right>i) r[i]=min(r[2*mid-i],right-i+1);
			while(i+r[i]<=len&&s[i+r[i]]==s[i-r[i]-1])
			{
				//substring s[i-r[i]-1,i+r[i]]
				gao(i-r[i]-1,i+r[i]);
				r[i]++;
			}
			if(i+r[i]-1>right)
			{
				right=i+r[i]-1;
				mid=i;
			}
			res=max(res,r[i]*2);
		}
		return res;
	}
}la;
char s[MAX];
void go()
{
	int len;
	while(read(s+1))
	{
		len=strlen(s+1);
		ans=0;
		ha.set(10,mod);
		ha.work(s,len);
		bkdr.work(s,len);
		la.work(s,len);
		printf("%lld\n",ans);
	}
}
