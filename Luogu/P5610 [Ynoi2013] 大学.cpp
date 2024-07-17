#include<bits/stdc++.h>
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
	#undef ll
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
const int MAX=1e5+10;
const int MAXV=5e5;
struct Disjoint_Set_Union
{
	vector<int> pre;
	void init(int n)
	{
		if(n<=0) return;
		pre.resize(n+2);
		for(int i=1;i<=n+1;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		pre[x]=y; // x -> y
		return 1;
	}
}dsu[MAXV];
struct Fenwick_Tree
{
	#define type ll
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,int *a)
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
vector<int> pos[MAXV];
int a[MAX];
int main()
{
	int n,m,i,j,op,l,r,p;
	ll lst,x;
	read(n,m);
	for(i=1;i<MAXV;i++) pos[i].clear();
	for(i=1;i<=n;i++)
	{
		read(a[i]);
		if(a[i]>1) pos[a[i]].push_back(i);
	}
	for(i=2;i<MAXV;i++)
	{
		for(j=i+i;j<MAXV;j+=i)
		{
			pos[i].insert(pos[i].end(),pos[j].begin(),pos[j].end());
		}
		for(j=1;j<pos[i].size();j++)
		{
			if(pos[i][j-1]>pos[i][j])
			{
				stable_sort(pos[i].begin(),pos[i].end());
				break;
			}
		}
		dsu[i].init(pos[i].size());
	}
	tr.init(n,a);
	lst=0;
	while(m--)
	{
		read(op,l,r);
		l^=lst;
		r^=lst;
		if(op==1)
		{
			read(x);
			x^=lst;
			if(x==1) continue;
			i=lower_bound(pos[x].begin(),pos[x].end(),l)-pos[x].begin()+1;
			for(;i<=pos[x].size() && pos[x][i-1]<=r;i=dsu[x].find(i+1))
			{
				p=pos[x][i-1];
				if(a[p]%x==0)
				{
					tr.upd(p,-(a[p]-a[p]/x));
					a[p]/=x;
				}
				if(a[p]<x||a[p]%x) dsu[x].merge(i,i+1,true);
			}
		}
		else printf("%lld\n",lst=tr.ask(l,r));
	}
	return 0;
}
