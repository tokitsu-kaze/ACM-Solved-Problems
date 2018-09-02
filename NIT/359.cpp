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
char a[MAX];
int main()
{
	int i,len,t,q,op,l,r;
	freopen("in.txt","w",stdout);
	srand(time(0));
	t=30;
	printf("%d\n",t);
	t--;
	len=100000;
	for(i=0;i<len;i++)
	{
		a[i]=(rand()%10)+'0';
	}
	a[len]='\0';
	puts(a);
	q=100000;
	printf("%d\n",q);
	while(q--)
	{
		if(q%2) op=1;
		else op=2;
		if(op==1)
		{
			l=rand()%len+1;
			r=rand()%10;
		}
		else
		{
			l=1;
			r=len;
		}
		printf("%d %d %d\n",op,l,r);
	}
	while(t--)
	{
		len=rand()%100000+1;
		for(i=0;i<len;i++)
		{
			a[i]=(rand()%10)+'0';
		}
		a[len]='\0';
		puts(a);
		q=rand()%100000+1;
		printf("%d\n",q);
		while(q--)
		{
			op=rand()%2+1;
			if(op==1)
			{
				l=rand()%len+1;
				r=rand()%10;
			}
			else
			{
				l=rand()%len+1;
				r=rand()%len+1;
				while(l>r)
				{
					l=rand()%len+1;
					r=rand()%len+1;
				}
				assert(l<=r);
			}
			printf("%d %d %d\n",op,l,r);
		}
	}
	return 0;
}
*/
struct Fenwick_Tree
{
	int bit[MAX];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void update(int x,int v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	int operator [](int x)
	{
		int res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
}bit;
char a[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,i,q,op,l,r,len,f[]={-1,1};
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %d",a+1,&q);
		len=strlen(a+1);
		bit.init(len);
		for(i=1;i<=len;i++) bit.update(i,(a[i]-'0')*f[i&1]);
		while(q--)
		{
			scanf("%d%d%d",&op,&l,&r);
			if(op==1)
			{
				bit.update(l,-(a[l]-'0')*f[l&1]);
				bit.update(l,r*f[l&1]);
				a[l]=r+'0';
			}
			else if(op==2) printf("%d\n",(bit[r]-bit[l-1])*f[l&1]);
		}
	}
	return 0;
}