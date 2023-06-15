#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace fastIO{
	#define BUF_SIZE 100000
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
	#undef ll
	#undef BUF_SIZE
};
using namespace fastIO;
const int MAX=1e7+10;
struct Cartesian_Tree
{
	int l[MAX],r[MAX],vis[MAX],stk[MAX];
	int build(int *a,int n)
	{
		int i,top=0;
		for(i=1;i<=n;i++) l[i]=r[i]=vis[i]=0;
		for(i=1;i<=n;i++)
		{
			int k=top;
			while(k>0&&a[stk[k-1]]>a[i]) k--;
			if(k) r[stk[k-1]]=i;
			if(k<top) l[i]=stk[k];
			stk[k++]=i;
			top=k;
		}
		for(i=1;i<=n;i++) vis[l[i]]=vis[r[i]]=1;
		for(i=1;i<=n;i++)
		{
			if(!vis[i]) return i;
		}
	}
}ct;
int a[MAX];
int main()
{
	int n,i;
	ll l,r;
	read(n);
	for(i=1;i<=n;i++) read(a[i]);
	ct.build(a,n);
	l=r=0;
	for(i=1;i<=n;i++)
	{
		l^=(1ll*i*(ct.l[i]+1));
		r^=(1ll*i*(ct.r[i]+1));
	}
	printf("%lld %lld\n",l,r);
	return 0;
}
