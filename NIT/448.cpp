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
const int MAX=5e4+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int a[MAX];
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	int i,n,q,l,r,k,cnt,t=5;
	printf("%d\n",t);
	t--;
	n=MAX-10;
	for(i=1;i<=n;i++) a[i]=i;
	cnt=llrand()%MAX+1;
	while(cnt--)
	{
		l=llrand()%n+1;
		r=llrand()%n+1;
		swap(a[l],a[r]);
	}
	printf("%d\n%d",n,a[1]);
	for(i=2;i<=n;i++) printf(" %d",a[i]);
	puts("");
	q=MAX-10;
	printf("%d\n",q);
	while(q--)
	{
		l=1;
		r=llrand()%n+1;
		k=llrand()%n+1;
		printf("%d %d %d\n",l,r,k);
	}
	while(t--)
	{
		n=llrand()%(MAX-10)+1;
		for(i=1;i<=n;i++) a[i]=i;
		cnt=llrand()%MAX;
		while(cnt--)
		{
			l=llrand()%n+1;
			r=llrand()%n+1;
			swap(a[l],a[r]);
		}
		printf("%d\n%d",n,a[1]);
		for(i=2;i<=n;i++) printf(" %d",a[i]);
		puts("");
		q=llrand()%(MAX-10)+1;
		printf("%d\n",q);
		while(q--)
		{
			l=llrand()%n+1;
			r=llrand()%(n-l+1)+l;
			assert(l<=r);
			assert(r<=n);
			k=llrand()%n+1;
			printf("%d %d %d\n",l,r,k);
		}
	}
	return 0;
}

int a[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
	int t,i,j,ans,q,l,r,k,len,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d",&l,&r,&k);
			len=r-l+1;
			k%=len;
			while(k--)
			{
				for(i=r;i>l;i--) swap(a[i],a[i-1]);
			}
			ans=0;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<i;j++)
				{
					if(a[j]>a[i]) ans^=1;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
*/
int bit[MAX],n;
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int v)
{
	while(x<=n)
	{
		bit[x]+=v;
		x+=lowbit(x);
	}
}
int getsum(int x)
{
	int res=0;
	while(x)
	{
		res+=bit[x];
		x-=lowbit(x);
	}
	return res;
}
int a[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,i,ans,q,l,r,k,len;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		mem(bit,0);
		ans=0;
		for(i=n;i>=1;i--)
		{
			ans+=getsum(a[i]);
			update(a[i],1);
		}
		ans%=2;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d",&l,&r,&k);
			len=r-l+1;
			k%=len;
			ans+=(len-1)*k;
			ans%=2;
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
1
4
2 3 1 4
3
1 3 2
2 4 1
2 3 1


3 1 2 4

3 4 1 2

3 1 4 2
*/