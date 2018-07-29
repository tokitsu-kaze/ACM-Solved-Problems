#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	#define ll long long
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
	template <class T> inline bool read(T &x){
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
	template<typename T,typename... U>inline bool read(T& head,U&... tail){return read(head)&&read(tail...);}
	//fwrite->print
	struct Ostream_fwrite{
		char *buf,*p1,*pend;
		Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
	//	void out(char ch){putchar(ch);}
		void out(char ch){if(p1==pend){fwrite(buf,1,BUF_SIZE,stdout);p1=buf;}*p1++=ch;}
		template <class T>void print(T x){
			static char s[15],*s1;s1=s;
			if(!x)*s1++='0';if(x<0)out('-'),x=-x;
			while(x)*s1++=x%10+'0',x/=10;
			while(s1--!=s)out(*s1);
		}
		void print(double x,int y){
			static ll mul[]=
			{1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,
			10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
			100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
			if(x<-1e-12)out('-'),x=-x;
			ll x2=(ll)floor(x);if(!y&&x-x2>=0.5)++x2;x-=x2;x*=mul[y];
			ll x3=(ll)floor(x);if(y&&x-x3>=0.5)++x3;print(x2);
			if(y>0){out('.');for(size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i);print(x3);}
		}
		void print(char *s){while(*s)out(*s++);}
		void print(const char *s){while(*s)out(*s++);}
		void flush(){if(p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
		~Ostream_fwrite(){flush();}
	}Ostream;
	template <class T>void print(T x){Ostream.print(x);}
	inline void print(char x){Ostream.out(x);}
	inline void print(char *s){Ostream.print(s);}
	inline void print(const char *s){Ostream.print(s);}
	inline void print(double x,int y){Ostream.print(x,y);}
	template<typename T,typename... U>inline void print(const T& head,const U&... tail){print(head);print(tail...);}
	inline void flush(){Ostream.flush();}
	#undef ll
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
void Main();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	Main();return 0;
}
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct hash_table
{
	ull seed;
	ull Hash[MAX],tmp[MAX];
	void set(ull _seed)
	{
		seed=_seed;
	}
	void work(char *s,int n)
	{
		ll i,j;
		tmp[0]=1;
		Hash[0]=0;
		for(i=1;i<=n;i++) tmp[i]=tmp[i-1]*seed;
		for(i=1;i<=n;i++) Hash[i]=(Hash[i-1]*seed+(s[i]-'a'));
	}
	ull get(int l,int r)
	{
		return (Hash[r]-Hash[l-1]*tmp[r-l+1]);
	}
}h;
char s[MAX];
VI res[MAX];
void Main()
{
	int i,j,len,tot;
	while(read(s+1))
	{
		len=strlen(s+1);
		for(i=len+1,j=1;j<=len;i++,j++) s[i]=s[j];
		h.set(23333);
		h.work(s,len*2);
		unordered_map<ull,int> mp;
		tot=0;
		for(i=1;i<=len;i++)
		{
			ull tmp=h.get(i,i+len-1);
			if(!mp.count(tmp)) mp[tmp]=++tot;
			res[mp[tmp]].pb(i-1);
		}
		print(tot,"\n");
		for(i=1;i<=tot;i++)
		{
			print(sz(res[i]));
			for(auto it:res[i]) print(' ',it);
			print('\n');
            res[i].clear();
		}
	}
}