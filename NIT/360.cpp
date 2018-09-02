#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
	freopen("in.txt","w",stdout);
	int t=9,n,q,op,l,r,x,y,i;
	printf("%d\n",t);
	t--;
	n=MAX-10;
	printf("%d\n",n);
	for(i=1;i<=n;i++) printf("%d%c",rand()%100+1," \n"[i==n]);
	for(i=1;i<=n;i++) printf("%d%c",rand()%100+1," \n"[i==n]);
	q=MAX-10;
	printf("%d\n",q);
	while(q--)
	{
		op=q%2+1;
		l=1;
		r=n;
		printf("%d %d %d ",op,l,r);
		if(op==1)
		{
				x=rand()%100+1;
				y=rand()%100+1;
				printf("%d %d\n",x,y);
		}
		else
		{
			x=rand()%100+1;
			printf("%d\n",x);
		}
	}
	while(t--)
	{
		n=(int)(llrand()%(MAX-10))+1;
		printf("%d\n",n);
		for(i=1;i<=n;i++) printf("%d%c",rand()%100+1," \n"[i==n]);
		for(i=1;i<=n;i++) printf("%d%c",rand()%100+1," \n"[i==n]);
		q=(int)(llrand()%(MAX-10))+1;
		printf("%d\n",q);
		while(q--)
		{
			op=rand()%2+1;
			l=rand()%n+1;
			r=rand()%(n-l+1)+l;
			assert(l<=r);
			assert(r<=n);
			printf("%d %d %d ",op,l,r);
			if(op==1)
			{
				x=rand()%100+1;
				y=rand()%100+1;
				printf("%d %d\n",x,y);
			}
			else
			{
				x=rand()%100+1;
				printf("%d\n",x);
			}
		}
	}
	return 0;
}
*/
/*
ll a[MAX],b[MAX];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ll i,n,t,q,op,l,r,x,y,cas=1;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=1;i<=n;i++) scanf("%lld",&b[i]);
		scanf("%lld",&q);
		printf("Case #%lld:\n",cas++);
		while(q--)
		{
			scanf("%lld%lld%lld",&op,&l,&r);
			if(op==1)
			{
				scanf("%lld%lld",&x,&y);
				for(i=l;i<=r;i++)
				{
					if(a[i]==x) a[i]=y;
				}
			}
			else
			{
				scanf("%lld",&x);
				ll ans=0;
				for(i=l;i<=r;i++)
				{
					if(a[i]==x) ans+=b[i];
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
*/

struct Segment_Tree
{
	int a[MAX],b[MAX];
	int s[MAX*17],top;
	int root[105],tot,ls[MAX*17],rs[MAX*17],v[MAX*17],ql,qr,qv,n;
	void init()
	{
		top=0;
		mem(root,0);
		ls[0]=rs[0]=0;
		v[0]=0;
		tot=1;
	}
	int newnode()
	{
		int t;
		if(top) t=s[--top];
		else t=tot++;
		ls[t]=rs[t]=0;
		v[t]=0;
		return t;
	}
	void delnode(int x)
	{
		s[top++]=x;
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
			v[id]+=qv;
			return ;
		}
		mid=(l+r)>>1;
		if(pos<=mid) insert(l,mid,ls[id],pos);
		else insert(mid+1,r,rs[id],pos);
		pushup(id);
	}
	void build(int _n)
	{
		int i;
		n=_n;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++)
		{
			qv=b[i];
			insert(1,n,root[a[i]],i);
		}
	}
	int merge(int a,int b)
	{
		if(!a||!b) return a+b;
		ls[a]=merge(ls[a],ls[b]);
		rs[a]=merge(rs[a],rs[b]);
		if(!ls[a]&&!rs[a]) v[a]+=v[b];
		else pushup(a);
		delnode(b);
		return a;
	}
	int split(int l,int r,int &id)
	{
		int mid,t;
		if(!id) return 0;
		if(ql<=l&&r<=qr)
		{
			int temp=id;
			id=0;
			return temp;
		}
		t=newnode();
		mid=(l+r)>>1;
		if(ql<=mid) ls[t]=split(l,mid,ls[id]);
		if(qr>mid) rs[t]=split(mid+1,r,rs[id]);
		pushup(t);
		pushup(id);
		return t;
	}
	int query(int l,int r,int id)
	{
		int mid,res=0;
		if(!id) id=newnode();
		if(l>=ql&&r<=qr) return v[id];
		mid=(l+r)>>1;
		if(ql<=mid) res+=query(l,mid,ls[id]);
		if(qr>mid) res+=query(mid+1,r,rs[id]);
		return res;
	}
	void work()
	{
		int q,x,y,op;	
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d%d%d",&ql,&qr,&x,&y);
				if(x!=y) root[y]=merge(root[y],split(1,n,root[x]));
			}
			else if(op==2)
			{
				scanf("%d%d%d",&ql,&qr,&x);
				printf("%d\n",query(1,n,root[x]));
			}
		}
	}
}tree;
int main()
{
//	freopen("in.txt","r",stdin);
	int n,t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tree.init();
		tree.build(n);
		printf("Case #%d:\n",cas++);
		tree.work();
	}
	return 0;
}
/*
1
5
1 2 3 4 5
1 1 1 1 1
10
2 1 3 2
1 1 5 1 2
2 1 3 2
1 1 5 3 2
1 1 5 4 2
1 1 5 5 2
2 1 5 2
2 1 5 5
1 1 5 2 5
2 1 5 5

*/