#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
namespace test
{
	const int MAX=2.5e5+10;
	mt19937 rd(time(0));
	int a[MAX],b[MAX],c[MAX];
	void work()
	{
		int i,j;
		int n=2.5e5;
		for(i=0;i<n;i++)
		{
			a[i]=rd()%1000000000+1;
			b[i]=rd()%1000000000+1;
			c[i]=b[i];
		}
		sort(c,c+n);
		int q=n;
		for(j=1;j<=q;j++)
		{
			int k=rd()%n;
			int cnt=0;
			ll sum=0;
			for(i=0;i<n;i++)
			{
				if(a[i]<b[(i+k)%n])
				{
					a[i]=b[(i+k)%n];
					cnt++;
				}
				if(j>700) sum+=n-(lower_bound(c,c+n,a[i])-c);
			}
			printf("%d %d %lld\n",j,cnt,sum);
		}
	}
}
const int MAX=2.5e5+10;
const int limt=1000;
int a[MAX],b[MAX];
int pos[MAX][305],tot[MAX];
pair<int,int> c[MAX];
int main()
{
//	test::work();
	int t,n,q,i,j,k,qi,x,tmp;
	ll sum;
	read(t);
	while(t--)
	{
		read(n,q);
		for(i=0;i<n;i++) read(a[i]);
		for(i=0;i<n;i++)
		{
			read(b[i]);
			c[i]={b[i],i};
			tot[i]=0;
		}
		sort(c,c+n);
		for(qi=1;qi<=q;qi++)
		{
			read(k);
			if(qi<limt)
			{
				sum=0;
				i=0;
				j=k;
				while(j<n)
				{
					a[i]=max(a[i],b[j]);
					sum+=a[i];
					i++;
					j++;
				}
				j=0;
				while(i<n)
				{
					a[i]=max(a[i],b[j]);
					sum+=a[i];
					i++;
					j++;
				}
			}
			else
			{
				if(qi==limt)
				{
					sum=0;
					for(i=0;i<n;i++)
					{
						x=lower_bound(c,c+n,pair<int,int>{a[i],-1})-c;
						for(j=x;j<n;j++)
						{
							tmp=c[j].second-i;
							if(tmp<0) tmp+=n;
							pos[tmp][tot[tmp]++]=i;
						}
						sum+=a[i];
					}
				}
				for(i=0;i<tot[k];i++)
				{
					int it=pos[k][i];
					x=it+k;
					if(x>=n) x-=n;
					if(a[it]<b[x])
					{
						sum+=b[x]-a[it];
						a[it]=b[x];
					}
				}
				tot[k]=0;
			}
			println(sum);
		}
	}
	return 0;
}
