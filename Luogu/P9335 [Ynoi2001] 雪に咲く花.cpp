#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE (1<<19)
	#define OUT_SIZE (1<<19)
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
	//fwrite->print
	struct Ostream_fwrite{
		char *buf,*p1,*pend;
		Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
//		void out(char ch){putchar(ch);}
		void out(char ch){if(p1==pend){fwrite(buf,1,BUF_SIZE,stdout);p1=buf;}*p1++=ch;}
		template<class T>void print(T x){
			static char s[33],*s1;s1=s;
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
	template<class T>void print(T x){Ostream.print(x);}
	inline void print(char x){Ostream.out(x);}
	inline void print(char *s){Ostream.print(s);}
	inline void print(string s){Ostream.print(s.c_str());}
	inline void print(const char *s){Ostream.print(s);}
	inline void print(double x,int y){Ostream.print(x,y);}
	template<class T,class... U>void print(const T& h,const U&... t){print(h);print(t...);}
	void println(){print('\n');}
	template<class T,class... U>void println(const T& h,const U&... t){print(h);println(t...);}
	inline void flush(){Ostream.flush();}
	#undef ll
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
struct gcd_stein
{
	#define type unsigned int
	#define ctz __builtin_ctz
	inline type gcd_stein_impl(type x,type y)
	{
		while(x!=y)
		{
			const type a=y-x;
			const type b=x-y;
			const int n=ctz(b);
			const type s=x<y?a:b;
			const type t=x<y?x:y;
			x=s>>n;
			y=t;
		}
		return x;
	}
	inline type gcd(type x,type y)
	{
		if(x==0||y==0) return x|y;
		const int n=ctz(x);
		const int m=ctz(y);
		return gcd_stein_impl(x>>n,y>>m)<<(n<m?n:m);
	}
	#undef type
}stein;
const int MAX=1e6+2;
const int MAXQ=5e6+2;
unsigned int a[MAX],b[MAX],c[MAX];
unsigned int ans[MAXQ],bit[MAX],tagsum[MAX];
int t[MAX],l[MAXQ],r[MAXQ],qid[MAXQ],id[MAXQ],tmp[MAX];
int main()
{
	int n,m,i,j,k,p;
	unsigned int x,y,z,now;
	read(n,m);
	for(i=1;i<=n;i++) read(a[i]);
	for(i=1;i<=n;i++) read(b[i]);
	for(i=1;i<=n;i++) read(c[i]);
//	for(i=0;i<=n;i++) tmp[i]=0;
	for(i=1;i<=m;i++)
	{
		read(l[i],r[i]);
		qid[i]=i;
		tmp[r[i]]++;
	}
	for(i=1;i<=n;i++) tmp[i]+=tmp[i-1];
	for(i=1;i<=m;i++) id[tmp[r[i]]--]=i;
	bit[0]=0;
	tagsum[0]=0;
	k=1;
	for(i=1;i<=n;i++)
	{
		for(j=i-1;j;j--)
		{
			x=a[j]&a[j+1];
			y=b[j]|b[j+1];
			z=stein.gcd(c[j],c[j+1]);
			if(x==a[j]&&y==b[j]&&z==c[j]) break;
			a[j]=x;
			b[j]=y;
			c[j]=z;
		}
		p=j+1;
		bit[i]=bit[i-1]+tagsum[i-1];
		for(j=p;j<=i;j++)
		{
			bit[j]+=tagsum[j]*(i-t[j]);
			tagsum[j]=tagsum[j-1]+a[j]*b[j]*c[j];
			t[j]=i;
		}
		now=bit[i]+tagsum[i];
		for(;r[id[k]]==i;k++)
		{
			p=l[id[k]]-1;
			ans[qid[id[k]]]=now-(bit[p]+tagsum[p]*(i-t[p]+1));
		}
	}
	for(i=1;i<=m;i++) println(ans[i]);
	return 0;
}
