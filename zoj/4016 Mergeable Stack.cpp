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
const int MAX=6e5+10;
const ll mod=1e9+7;
int id[MAX],l[MAX],r[MAX],v[MAX],tot,tail[MAX];
void insert(int &x,int val)
{
	int t=++tot;
	v[x]=val;
	l[t]=x;
	r[x]=t;
	tail[t]=tail[x];
	x=t;
}
void pop(int &x)
{
	if(l[x]==-1)
	{
		puts("EMPTY");
		return ;
	}
	printf("%d\n",v[l[x]]);
	v[x]=-1;
	int t=x;
	x=l[x];
	r[t]=t;
	l[t]=-1;
	r[x]=x;
	tail[x]=tail[t];
}
void merge(int &a,int &b)
{
	int t;
	if(l[a]==-1)
	{
		swap(a,b);
		return;
	}
	if(l[b]==-1) return;
	l[tail[b]]=l[a];
	tail[b]=tail[a];
	tail[l[b]]=tail[a];
	a=b;
	b=++tot;
	tail[b]=b;
	l[b]=-1;
}
void debug(int x)
{
	int i;
	puts("*****");
	for(i=l[x];~i;i=l[i])
	{
//		cout<<i<<endl;
		printf("%d ",v[i]);
	}
	puts("");
	for(i=l[x];~i;i=l[i])
	{
//		cout<<i<<endl;
		printf("%d ",tail[i]);
	}
	puts("");
	puts("*****");
}
int main()
{
	int t,n,i,q,op,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		tot=0;
		for(i=1;i<=n;i++)
		{
			id[i]=tail[i]=++tot;
			r[i]=i;
			l[i]=-1;
		}
		while(q--)
		{
			scanf("%d%d",&op,&a);
			if(op==1)
			{
				scanf("%d",&b);
				insert(id[a],b);
			}
			else if(op==2) pop(id[a]);
			else if(op==3)
			{
				scanf("%d",&b);
	//			cout<<tail[id[a]]<<" "<<tail[id[b]]<<endl;
	//			cout<<l[id[a]]<<" "<<l[id[b]]<<endl;
				merge(id[a],id[b]);
			}
	//		debug(id[a]);
		}
	}
	return 0;
} 
/*
100
2 100
1 1 1
1 1 2
1 2 3
1 2 4
3 1 2
1 1 5
3 1 2
1 1 100
3 1 2

*/