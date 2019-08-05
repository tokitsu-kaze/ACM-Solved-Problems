////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-07 18:52:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4417
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:24016KB
//////////////////System Comment End//////////////////
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int l,r,sum;
}tree[20*MAX];
int root[MAX],a[MAX],Hash[MAX],tot;
void insert(int l,int r,int &id,int pre,int pos)
{
	int mid;
	tree[++tot]=tree[pre];
	tree[tot].sum++;
	id=tot;
	if(l==r) return;
	mid=(l+r)/2;
	if(mid>=pos) insert(l,mid,tree[id].l,tree[pre].l,pos);
	else insert(mid+1,r,tree[id].r,tree[pre].r,pos);
}
int query(int l,int r,int id,int pre,int k)
{
	int mid,temp;
	if(l==r) return Hash[l];
	mid=(l+r)/2;
	temp=tree[tree[pre].l].sum-tree[tree[id].l].sum;
	if(temp>=k) return query(l,mid,tree[id].l,tree[pre].l,k);
	else return query(mid+1,r,tree[id].r,tree[pre].r,k-temp);
}
int main()
{
	int n,m,l,r,k,i,pos,t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			Hash[i]=a[i];
		}
		tot=0;
		sort(Hash+1,Hash+n+1);
		for(i=1;i<=n;i++)
		{
			pos=lower_bound(Hash+1,Hash+n+1,a[i])-Hash;
			insert(1,n,root[i],root[i-1],pos);
		}
		printf("Case %d:\n",cas++);
		while(m--)
		{
			scanf("%d%d%d",&l,&r,&k);
			l++;
			r++;
			int ll,rr,mid;
			ll=1;
			rr=r-l+1;
			while(ll<rr)
			{
				mid=(ll+rr)>>1;
				if(query(1,n,root[l-1],root[r],mid+1)<=k) ll=mid+1;
				else rr=mid;
			}
			if(query(1,n,root[l-1],root[r],ll)<=k) printf("%d\n",ll);
			else puts("0");
		}
	}
	return 0;
}