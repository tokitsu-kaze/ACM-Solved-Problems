#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
	//inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
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
	inline bool read_line(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;ch!='\n'&&!IOerror;ch=nc())*s++=ch;
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
typedef long long ll;
const int MAX=2e5+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		tmp[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=a[i];
			tmp[i]+=tmp[i-1];
			bit[i]=tmp[i]-tmp[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	void upd(int x,type v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr;
struct node{int x,y,z,id;}a[MAX],tmp[MAX];
int tot,in[MAX],n;
void cdq1(int l,int r)
{
	if(l==r) return;
	int mid,i,j,k;
	mid=(l+r)>>1;
	cdq1(l,mid);
	cdq1(mid+1,r);
	i=l;
	j=mid+1;
	tot=0;
	while(i<=mid&&j<=r)
	{
		if(a[i].y<a[j].y)
		{
			tr.upd(a[i].z,1);
			tmp[++tot]=a[i++];
		}
		else
		{
			in[a[j].id]+=tr.ask(1,a[j].z-1);
			tmp[++tot]=a[j++];
		}
	}
	while(j<=r)
	{
		in[a[j].id]+=tr.ask(1,a[j].z-1);
		tmp[++tot]=a[j++];
	}
	for(k=l;k<i;k++) tr.upd(a[k].z,-1);
	while(i<=mid) tmp[++tot]=a[i++];
	for(i=1;i<=tot;i++) a[l+i-1]=tmp[i];
}
void cdq2(int l,int r)
{
	if(l==r) return;
	int mid,i,j,k;
	mid=(l+r)>>1;
	cdq2(l,mid);
	cdq2(mid+1,r);
	i=l;
	j=mid+1;
	tot=0;
	while(i<=mid&&j<=r)
	{
		if(a[i].y>a[j].y)
		{
			tr.upd(a[i].z,1);
			tmp[++tot]=a[i++];
		}
		else
		{
			in[a[j].id]-=tr.ask(a[j].z+1,n);
			tmp[++tot]=a[j++];
		}
	}
	while(j<=r)
	{
		in[a[j].id]-=tr.ask(a[j].z+1,n);
		tmp[++tot]=a[j++];
	}
	for(k=l;k<i;k++) tr.upd(a[k].z,-1);
	while(i<=mid) tmp[++tot]=a[i++];
	for(i=1;i<=tot;i++) a[l+i-1]=tmp[i];
}
int f[MAX],g[MAX];
int main()
{
	int k,i,j,x,y,z;
	ll ans;
	read(n);
	for(i=1;i<=n;i++) read(f[i]);
	for(i=1;i<=n;i++) read(g[i]);
	for(i=1;i<=n;i++) a[i]={i,f[i],g[i],i};
/*	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(f[i]<f[j]&&g[i]<g[j]) in[j]++;
			else in[i]++;
		}
	}*/
	tr.init(n);
	cdq1(1,n);
	for(i=1;i<=n;i++)
	{
		a[i]={n-i+1,f[n-i+1],g[n-i+1],n-i+1};
		in[i]+=n-i;
	}
	cdq2(1,n);
	ans=1LL*n*(n-1)*(n-2)/6;
	for(i=1;i<=n;i++)
	{
		ans-=1LL*in[i]*(in[i]-1)/2;
//		printf("%d %d\n",i,in[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
9
3 7 2 1 4 5 9 8 7
2 4 1 5 7 9 2 4 1

1 4
2 8
3 2
4 3
5 6
6 7
7 3
8 3
9 0
*/
