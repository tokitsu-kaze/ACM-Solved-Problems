#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct FastIO  
{  
	static const int S=200;  
	int wpos;  
	char wbuf[S];  
	FastIO():wpos(0){}  
	inline int xchar()  
	{  
		static char buf[S];  
		static int len=0,pos=0;  
		if(pos==len) pos=0,len=fread(buf,1,S,stdin);  
		if(pos==len) exit(0);  
		return buf[pos++];  
	}  
	inline int read()  
	{  
		int s=1,c=xchar(),x=0;  
		while(c<=32) c=xchar();  
		if(c=='-') s=-1,c=xchar();  
		for(;'0'<=c&&c<='9';c=xchar()) x=x*10+c-'0';  
		return x*s;  
	}  
	~FastIO()  
	{  
		if(wpos) fwrite(wbuf,1,wpos,stdout),wpos=0;  
	}  
}io;
struct Segment_Tree
{
	int tot,ls[MAX*24],rs[MAX*24],v[MAX*24],ql,qr,qv;
	void init()
	{
		ls[0]=rs[0]=0;
		v[0]=0; 
		tot=1;
	}
	int newnode()
	{
		ls[tot]=rs[tot]=0;
		v[tot]=0;
		return tot++;
	}
	void pushup(int id)
	{
		v[id]=v[ls[id]]+v[rs[id]];
	}
	void insert(int l,int r,int &id,int pos)
	{
		int mid;
		if(!id) id=newnode();
		if(l==r)
		{
			v[id]++;
			return;
		}
		mid=(l+r)>>1;
		if(pos<=mid) insert(l,mid,ls[id],pos);
		else if(pos>=mid+1) insert(mid+1,r,rs[id],pos);
		pushup(id);
	}
	int query(int l,int r,int id)
	{
		int res=0;
		if(l>=ql&&r<=qr) return v[id];
		int mid=(l+r)>>1;
		if(ql<=mid) res+=query(l,mid,ls[id]);
		if(qr>mid) res+=query(mid+1,r,rs[id]);
		return res;
	}
}tr;
ll bit[MAX];
int main()
{
	int n,q,i,x;
	while(n=io.read())
	{
		q=io.read();
		bit[0]=0;
		map<int,int> root;
		tr.init();
		for(i=1;i<=n;i++)
		{
			x=io.read();
			if(!root.count(x)) root[x]=0;
			tr.insert(1,n,root[x],i);
			bit[i]=x;
			bit[i]+=bit[i-1];
		}
		while(q--)
		{
			tr.ql=io.read();
			tr.qr=io.read();
			x=io.read();
			printf("%d %lld\n",tr.query(1,n,root[x]),bit[tr.qr]-bit[tr.ql-1]);
		}
	}
	return 0;
}

/*
int a[MAX];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,q,i,l,r,x;
	while(~scanf("%d%d",&n,&q))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		while(q--)
		{
			scanf("%d%d%d",&l,&r,&x);
			int ans=0;
			ll res=0;
			for(i=l;i<=r;i++)
			{
				if(a[i]==x) ans++;
				res+=a[i];
			}
			printf("%d %lld\n",ans,res);
		}
	}
	return 0;
}
*/
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int main()
{
	srand(time(0));
	freopen("in1.txt","w",stdout);
	ll n,m,t=3,i,l,r,x;
	while(t--)
	{
		n=(ll)100000;
		m=(ll)100000;
		printf("%lld %lld\n",n,m);
		for(i=1;i<=n;i++) printf("%lld%c",(ll)llrand()%10000000+1," \n"[i==n]);
		while(m--)
		{
			l=llrand()%n+1;
			r=llrand()%(n-l+1)+l;
			assert(l<=r);
			assert(r<=n);
			printf("%lld %lld %lld\n",l,r,(ll)llrand()%10000000+1);
		}
	}
	n=(ll)100000;
	m=(ll)100000;
	printf("%lld %lld\n",n,m);
	for(i=1;i<=n;i++) printf("%lld%c",(ll)llrand()%10000000+1," \n"[i==n]);
	while(m--)
	{
		l=1;
		r=n;
		printf("%lld %lld %lld\n",l,r,(ll)llrand()%10000000+1);
	}
	n=(ll)100000;
	m=(ll)100000;
	printf("%lld %lld\n",n,m);
	for(i=1;i<=n;i++) printf("%lld%c",(ll)10000000," \n"[i==n]);
	while(m--)
	{
		l=1;
		r=n;
		printf("%lld %lld %lld\n",l,r,(ll)10000000);
	}
	return 0;
}
*/